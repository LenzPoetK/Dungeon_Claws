
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println(" ______            _        _______  _______  _______  _          _______  _        _______           _______ ");
        System.out.println("(  __  \\ |\\     /|( (    /|(  ____ \\(  ____ \\(  ___  )( (    /|  (  ____ \\( \\      (  ___  )|\\     /|(  ____ \\");
        System.out.println("| (  \\  )| )   ( ||  \\  ( || (    \\/| (    \\/| (   ) ||  \\  ( |  | (    \\/| (      | (   ) || )   ( || (    \\/");
        System.out.println("| |   ) || |   | ||   \\ | || |      | (__    | |   | ||   \\ | |  | |      | |      | (___) || | _ | || (_____ ");
        System.out.println("| |   | || |   | || (\\ \\) || | ____ |  __)   | |   | || (\\ \\) |  | |      | |      |  ___  || |( )| |(_____  )");
        System.out.println("| |   ) || |   | || | \\   || | \\_  )| (      | |   | || | \\   |  | |      | |      | (   ) || || || |      ) |");
        System.out.println("| (__/  )| (___) || )  \\  || (___) || (____/\\| (___) || )  \\  |  | (____/\\| (____/\\| )   ( || () () |/\\____) |");
        System.out.println("(______/ (_______)|/    )_)(_______)(_______/(_______)|/    )_)  (_______/(_______/|/     \\|(_______)\\_______)\n");

        System.out.print(">> Press any key to continue <<");
        scanner.nextLine();
        
        while(true){
            char option;

            ClearConsole.clear();

            System.out.println("> Play (P)");
            System.out.println("> Tutorial (T)");
            System.out.println("> Exit (E)\n");

            System.out.print("Chose one option: ");
            option = scanner.next().charAt(0);
            scanner.nextLine();

            if(option == 'P'){
                char attributeOption;
                int attributePoints = 15;
                String name;
                int hp;
                int strength = 0;
                int constuition = 0;
                int defense = 0;
                int agility = 0;

                ClearConsole.clear();
               
                System.out.print("Enter your adventurer's name: ");
                name = scanner.nextLine();

                while(true){
                    ClearConsole.clear();

                    System.out.println("Adventurer: " + name + "\n");
                    System.out.printf("You have %d attribute points to distribute\n", attributePoints);
                    System.out.println("ATTRIBUTES:");
                    System.out.println("> Constituition (C): " + constuition);
                    System.out.println("> Strength (S): " + strength);
                    System.out.println("> Agility (A): " + agility);
                    System.out.println("> Defense (D): " + defense + "\n");

                    if(attributePoints == 0) {
                        char confirmOption;
                        System.out.println("> YES (Y)");
                        System.out.println("> NO (N)");
                        System.out.print("Confirm your choices?: ");
                        confirmOption = scanner.next().charAt(0);

                        if(confirmOption == 'Y'){
                            break;
                        }
                        else if(confirmOption == 'N'){
                            attributePoints = 15;
                            constuition = 0;
                            strength = 0;
                            agility = 0;
                            defense = 0;
                            continue;
                        }
                        else{
                            System.out.println("Select a valid option.");
                            scanner.nextLine();
                            continue;
                        }
                    }

                    System.out.print("Chose an attribute to add points: ");
                    attributeOption = scanner.next().charAt(0);
                    scanner.nextLine();

                    if(attributeOption == 'C'){
                        ClearConsole.clear();
                        System.out.println("Points for constituition: ");
                        constuition = scanner.nextInt();
                        scanner.nextLine();
                        attributePoints -= constuition;
                    }
                    else if(attributeOption == 'A'){
                        ClearConsole.clear();
                        System.out.println("Points for constituition: ");
                        agility = scanner.nextInt();
                        scanner.nextLine();
                        attributePoints -= agility;
                    }
                    else if(attributeOption == 'S'){
                        ClearConsole.clear();
                        System.out.println("Points for strength: ");
                        strength = scanner.nextInt();
                        scanner.nextLine();
                        attributePoints -= strength;
                    }
                    else if(attributeOption == 'D'){
                        ClearConsole.clear();
                        System.out.println("Points for defense: ");
                        defense = scanner.nextInt();
                        scanner.nextLine();
                        attributePoints -= defense;
                    }
                    else{
                        ClearConsole.clear();
                        System.out.println("Select a valid option.");
                        scanner.nextLine();
                    }
                }
            }
            else if(option == 'T'){
                ClearConsole.clear();
                System.out.println("Tutorial\n");

                System.out.print(">> Press any key to return <<");
                scanner.nextLine();
            }
            else if(option == 'E'){
                ClearConsole.clear();
                System.out.println("Sair");
                break;
            }
            else{
                ClearConsole.clear();
                System.out.println("Select a valid option.");
                scanner.nextLine();
            }
        }
    }
}
