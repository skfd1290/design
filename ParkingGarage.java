import java.util.*;

class Car {
    String plate;
    int moveCount;

    Car(String plate) {
        this.plate = plate;
        this.moveCount = 0;
    }
}

public class ParkingGarage {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Stack<Car> garage = new Stack<>();
        int capacity = 10;

        while (true) {
            System.out.println("\nEnter A (Arrival), D (Departure), E (Exit): ");
            char choice = sc.next().toUpperCase().charAt(0);

            if (choice == 'E') {
                System.out.println("Exiting program...");
                break;
            }

            if (choice == 'A') {
                System.out.print("Enter license plate: ");
                String plate = sc.next();

                if (garage.size() < capacity) {
                    garage.push(new Car(plate));
                    System.out.println("Car " + plate + " arrived. Space available.");
                } else {
                    System.out.println("Car " + plate + " arrived. No space available.");
                }

            } else if (choice == 'D') {
                System.out.print("Enter license plate: ");
                String plate = sc.next();

                Stack<Car> temp = new Stack<>();
                boolean found = false;
                Car targetCar = null;

                while (!garage.isEmpty()) {
                    Car topCar = garage.pop();

                    if (topCar.plate.equals(plate)) {
                        targetCar = topCar;
                        found = true;
                        break;
                    } else {
                        topCar.moveCount++;
                        temp.push(topCar);
                    }
                }

                if (found) {
                    System.out.println("Car " + plate + " departed. Moved " + targetCar.moveCount + " times.");
                } else {
                    System.out.println("Car " + plate + " not found in garage.");
                }

                // Restore cars
                while (!temp.isEmpty()) {
                    garage.push(temp.pop());
                }

            } else {
                System.out.println("Invalid input. Please enter A, D, or E.");
            }
        }

        sc.close();
    }
}
