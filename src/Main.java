
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        Random random = new Random();
        ClearConsole.clear();

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

            //Main menu
            System.out.println("> Play (P)");
            System.out.println("> Tutorial (T)");
            System.out.println("> Exit (E)\n");

            System.out.print("Chose one option: ");
            option = Character.toUpperCase(scanner.nextLine().charAt(0));

            if(option == 'P'){
                //Variables declaration
                int attributePoints = 15;
                String name;
                int hp = 0;

                Player player = new Player(null, 0, 0, 0, 0, 0);
                ClearConsole.clear();
               
                while (true){
                    System.out.print("Enter your adventurer's name: ");
                    name = scanner.nextLine();
                    if (name.length() > 0){
                        player.setName(name);
                        break;
                    }else{
                        player.setName("Noname");
                        break;
                    }
                }
                

                player.levelUp(attributePoints);

                
                //Rolls D6 for defining player HP
                hp += random.nextInt(6) + 1;
                hp += random.nextInt(6) + 1;
                hp += random.nextInt(6) + 1;
                hp += player.getConstuition();
                player.setHp(hp);
                
                player.showDetails();
                scanner.nextLine();


                player.levelUp(5);
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
