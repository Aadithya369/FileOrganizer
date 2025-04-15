choice = 0
while choice != 4 || choice != 5:
    
    choice =int(input("1.Add task\n2.Remove task\n3.Modify Task\n4.Save and exit\n5.Exit without saving\n"))
    task = input("Enter the task to add: ")
    file = open("to_do_list.txt",'w')
    file.write(task)

