
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        Player player = new Player(null, 0, 0, 0, 0, 0);
        Scanner scanner = new Scanner(System.in);
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
                
                //levelUP is just a attribute distribution for the player
                player.levelUp(attributePoints);
                
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

        Weapon adaga = new Weapon(4, "Light");
        Weapon espada = new Weapon(5, "Light");
        Weapon machado = new Weapon(4, "Heavy");


        while (true) {
            System.out.println("Now you must choose a weapon to acompany you");
            System.out.println("(A)daga");

            break;
        }

        firstRandomBattle();
        player.levelUp(5);

        secondRandomBattle();
        player.levelUp(10);


        thirdRandomBattle();
        // endgame();
        scanner.close();
    }

    private static void firstRandomBattle() {
        Random random = new Random();
        Enemy redGoblin = new Enemy(2, 5, 2, 15, "Red Goblin");
        Enemy greenGoblin = new Enemy(2, 5, 2, 15, "Green Goblin");
        Enemy blueGoblin = new Enemy(2, 5, 2, 15, "Blue Goblin");

        int randomEnemyChoice = random.nextInt(3);

        switch (randomEnemyChoice) {
            case 0:
                // player.battle(redGoblin);
                break;
            case 1:
                // player.battle(greenGoblin);
                break;
            case 2:
                // player.battle(blueGoblin);
        }
    }

    private static void secondRandomBattle(){
        Random random = new Random();
        Enemy redOrc = new Enemy(2, 5, 2, 15, "Red Orc");
        Enemy BlueOrc = new Enemy(2, 5, 2, 15, "blue Orc");

        int randomEnemyChoice = random.nextInt(3);

        switch (randomEnemyChoice) {
            case 0:
                // player.battle(redOrc);
                break;
            case 1:
                // player.battle(blueOrc);
                break;
            case 2:
        }
    }
    private static void thirdRandomBattle(){
        Enemy redDragon = new Enemy(10, 10, 10, 30, "Red Dragon");
    }
}
