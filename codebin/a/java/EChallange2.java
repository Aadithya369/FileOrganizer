class EChallange extends Exception {
    public EChallange(String message) {
        super(message); // Pass the error message to the Exception class
    }
}

class AgeValidator {
    void checkAge(int age) throws EChallange {
        if (age < 0) {
            throw new EChallange("Age is less than 0");
        } else if (age > 150) {
            throw new EChallange("Age is greater than 150");
        } else {
            System.out.println("Age is valid: " + age);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        AgeValidator validator = new AgeValidator();

        try {
            validator.checkAge(200); // Example of invalid age
        } catch (EChallange e) {
            System.out.println("Exception caught: " + e.getMessage());
        }

        try {
            validator.checkAge(30); // Example of valid age
        } catch (EChallange e) {
            System.out.println("Exception caught: " + e.getMessage());
        }
    }
}

