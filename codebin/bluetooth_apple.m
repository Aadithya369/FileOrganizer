#include "bluetooth.h"

#import <IOBluetooth/IOBluetooth.h>

@interface IOBluetoothDevice()
    @property (nonatomic) uint8_t batteryPercentCase;
    @property (nonatomic) uint8_t batteryPercentCombined;
    @property (nonatomic) uint8_t batteryPercentLeft;
    @property (nonatomic) uint8_t batteryPercentRight;
    @property (nonatomic) uint8_t batteryPercentSingle;
@end

const char* ffDetectBluetooth(FFBluetoothOptions* options, FFlist* devices /* FFBluetoothResult */)
{
    NSArray<IOBluetoothDevice*>* ioDevices = IOBluetoothDevice.pairedDevices;
    if(!ioDevices)
        return "IOBluetoothDevice.pairedDevices failed";

    for(IOBluetoothDevice* ioDevice in ioDevices)
    {
        if (!options->showDisconnected && !ioDevice.isConnected)
            continue;

        FFBluetoothResult* device = ffListAdd(devices);
        ffStrbufInitS(&device->name, ioDevice.name.UTF8String);
        ffStrbufInitS(&device->address, ioDevice.addressString.UTF8String);
        ffStrbufReplaceAllC(&device->address, '-', ':');
        ffStrbufUpperCase(&device->address);
        ffStrbufInit(&device->type);

        if (ioDevice.batteryPercentSingle)
            device->battery = ioDevice.batteryPercentSingle;
        else if (ioDevice.batteryPercentCombined)
            device->battery = ioDevice.batteryPercentCombined;
        else if (ioDevice.batteryPercentCase)
            device->battery = ioDevice.batteryPercentCase;

        device->connected = !!ioDevice.isConnected;
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorLimitedDiscoverableMode)
            ffStrbufAppendS(&device->type, "Limited Discoverable Mode, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorReserved1)
            ffStrbufAppendS(&device->type, "LE audio, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorReserved2)
            ffStrbufAppendS(&device->type, "Reserved for future use, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorPositioning)
            ffStrbufAppendS(&device->type, "Positioning, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorNetworking)
            ffStrbufAppendS(&device->type, "Networking, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorRendering)
            ffStrbufAppendS(&device->type, "Rendering, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorCapturing)
            ffStrbufAppendS(&device->type, "Capturing, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorObjectTransfer)
            ffStrbufAppendS(&device->type, "Object Transfer, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorAudio)
            ffStrbufAppendS(&device->type, "Audio, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorTelephony)
            ffStrbufAppendS(&device->type, "Telephony, ");
        if(ioDevice.serviceClassMajor & kBluetoothServiceClassMajorInformation)
            ffStrbufAppendS(&device->type, "Information, ");

        if(device->type.length == 0)
        {
            switch(ioDevice.deviceClassMajor)
            {
                case kBluetoothDeviceClassMajorMiscellaneous:
                    ffStrbufAppendS(&device->type, "Miscellaneous");
                    break;
                case kBluetoothDeviceClassMajorComputer:
                    ffStrbufAppendS(&device->type, "Computer");
                    break;
                case kBluetoothDeviceClassMajorPhone:
                    ffStrbufAppendS(&device->type, "Phone");
                    break;
                case kBluetoothDeviceClassMajorLANAccessPoint:
                    ffStrbufAppendS(&device->type, "LAN/Network Access point");
                    break;
                case kBluetoothDeviceClassMajorAudio:
                    ffStrbufAppendS(&device->type, "Audio/Video");
                    break;
                case kBluetoothDeviceClassMajorPeripheral:
                    ffStrbufAppendS(&device->type, "Peripheral");
                    break;
                case kBluetoothDeviceClassMajorImaging:
                    ffStrbufAppendS(&device->type, "Imaging");
                    break;
                case kBluetoothDeviceClassMajorWearable:
                    ffStrbufAppendS(&device->type, "Wearable");
                    break;
                case kBluetoothDeviceClassMajorToy:
                    ffStrbufAppendS(&device->type, "Toy");
                    break;
                case kBluetoothDeviceClassMajorHealth:
                    ffStrbufAppendS(&device->type, "Health");
                    break;
                case kBluetoothDeviceClassMajorUnclassified:
                    ffStrbufAppendS(&device->type, "Uncategorized");
                    break;
                default:
                    ffStrbufAppendS(&device->type, "Unknown");
                    break;
            }
        }
        else
        {
            ffStrbufTrimRight(&device->type, ' ');
            ffStrbufTrimRight(&device->type, ',');
        }
    }

    return NULL;
}
