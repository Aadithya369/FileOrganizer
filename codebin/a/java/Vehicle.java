class Vehicle {
    void start() {
        System.out.println("Vehicle is started");
    }

    void stop() {
        System.out.println("Vehicle is stopped");
    }
}

class Car extends Vehicle {
    String brand = "BMW";

    void start() {
        System.out.println("Car is starting");
    }

    void stop() {
        System.out.println("Car stopped");
    }
}

class Bike extends Vehicle {
    String bikeBrand = "TVS Raider";

    void start() {
        System.out.println("Bike is starting");
    }

    void stop() {
        System.out.println("Bike stopped");
    }
}

public class Main {
    public static void main(String[] args) {
        Car car = new Car();
        Bike bike = new Bike();

        car.start();
        car.stop();
        bike.start();
        bike.stop();
    }
}

