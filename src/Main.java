
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        //titulo do game
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

            //menu principal
            System.out.println("> Play (P)");
            System.out.println("> Tutorial (T)");
            System.out.println("> Exit (E)\n");

            System.out.print("Chose one option: ");
            option = scanner.next().charAt(0);
            scanner.nextLine();

            if(option == 'P'){
                //Declaracao de variaveis
                char attributeOption;
                int attributePoints = 15;
                String name;
                int hp = 0;
                int strength = 0;
                int constuition = 0;
                int agility = 0;

                ClearConsole.clear();
               
                System.out.print("Enter your adventurer's name: ");
                name = scanner.nextLine();

                while(true){
                    ClearConsole.clear();

                    //tela de selecao para distrubuir os pontos
                    System.out.println("Adventurer: " + name + "\n");
                    System.out.printf("You have %d attribute points to distribute\n", attributePoints);
                    System.out.println("ATTRIBUTES:");
                    System.out.println("> Constituition (C): " + constuition);
                    System.out.println("> Strength (S): " + strength);
                    System.out.println("> Agility (A): " + agility + "\n");

                    if(attributePoints <= 0) {
                        //confirmacao dos pontos atribuidos
                        char confirmOption;
                        System.out.println("> PROCEED (Y)");
                        System.out.println("> REDISTRIBUTE POINTS (N)");
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
                        int constituitionAdd;
                        ClearConsole.clear();
                        System.out.println("Points for constituition: ");
                        constituitionAdd = scanner.nextInt();
                        constuition = constituitionAdd >= 0 ? constituitionAdd : constuition;
                        scanner.nextLine();

                        if(constituitionAdd >= 0){
                            attributePoints -= constuition;
                        }
                        else {
                            ClearConsole.clear();
                            System.out.println("You can't remove points. If you want to redistribute, use all your points first.");
                            scanner.nextLine();
                        }
                    }
                    else if(attributeOption == 'A'){
                        int agilityAdd;
                        ClearConsole.clear();
                        System.out.println("Points for constituition: ");
                        agilityAdd = scanner.nextInt();
                        agility = agilityAdd >= 0 ? agilityAdd : agility;
                        scanner.nextLine();

                        if(agilityAdd >= 0){
                            attributePoints -= agility;
                        }
                        else{
                            ClearConsole.clear();
                            System.out.println("You can't remove points. If you want to redistribute, use all your points first.");
                            scanner.nextLine();
                        }
                    }
                    else if(attributeOption == 'S'){
                        int strengthAdd;
                        ClearConsole.clear();
                        System.out.println("Points for strength: ");
                        strengthAdd = scanner.nextInt();
                        strength = strengthAdd >= 0 ? strengthAdd : strength;
                        scanner.nextLine();

                        if(strengthAdd >= 0){
                            attributePoints -= strength;
                        }
                        else{
                            ClearConsole.clear();
                            System.out.println("You can't remove points. If you want to redistribute, use all your points first.");
                            scanner.nextLine();
                        }
                    }
                    else{
                        ClearConsole.clear();
                        System.out.println("Select a valid option.");
                        scanner.nextLine();
                    }
                }
                ClearConsole.clear();
                scanner.nextLine();
                hp += random.nextInt(6) + 1;
                hp += random.nextInt(6) + 1;
                hp += random.nextInt(6) + 1;
                hp += constuition;

                Player player = new Player(name, hp, constuition, strength, agility);
                player.showDetails();
                scanner.nextLine();
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
        scanner.close();
    }
}
