
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
        System.out.println("(______/ (_______)|/    )_)(_______)(_______/(_______)|/    )_)  (_______/(_______/|/     \\|(_______)\\_______)\n\n");

        System.out.print("                                          >> Press enter to continue <<");
        scanner.nextLine();

        Player player = new Player(null, 0, 0 , 0, 0, 0);
        Enemy girasTheMage = new Enemy(0, 0, 0, 0, null, 0, 0, 0, 0);
        Enemy dragon = new Enemy(0, 0, 0, 0, null, 0, 0, 0, 0);
        Weapon dagger = new Weapon("Light", 4);
        Weapon heavySword = new Weapon("Heavy", 8);
        Armor bananeira = new Armor(2);
        
        GAME:
        while (true) {
            char option;
            ClearConsole.clear();
            System.out.println("> Play (P)");
            System.out.println("> Credits (C)");
            System.out.println("> Exit (E)\n");
            System.out.print("Chose one option: ");
            option = Character.toUpperCase(scanner.nextLine().charAt(0));

            switch (option) {
                case 'P' -> {
                    //Variables declaration
                    char attributeOption;
                    int attributePoints = 15;
                    String name;
                    int hp = 0;
                    int strength = 0;
                    int dexterity = 0;
                    int constuition = 0;
                    int agility = 0;
                    ClearConsole.clear();
                    System.out.print("Enter your adventurer's name: ");
                    name = scanner.nextLine();

                    attributeDistribution:
                    while (true) {
                        ClearConsole.clear();
                        System.out.println("Adventurer: " + name + "\n");
                        System.out.printf("You have %d attribute points to distribute\n", attributePoints);
                        System.out.println("ATTRIBUTES:");
                        System.out.println("> Constituition (C): " + constuition);
                        System.out.println("> Strength (S): " + strength);
                        System.out.println("> Dexterity (D): " + dexterity);
                        System.out.println("> Agility (A): " + agility + "\n");

                        if (attributePoints <= 0) {
                            char confirmOption;
                            System.out.println("> PROCEED (Y)");
                            System.out.println("> REDISTRIBUTE POINTS (N)");
                            System.out.print("Confirm your choices?: ");
                            confirmOption = Character.toUpperCase(scanner.next().charAt(0));
                            
                            switch (confirmOption) {
                                case 'Y' -> {
                                    break attributeDistribution;
                                }
                                case 'N' -> {
                                    attributePoints = 15;
                                    constuition = 0;
                                    strength = 0;
                                    dexterity = 0;
                                    agility = 0;
                                    continue;
                                }
                                default -> {
                                    System.out.println("Select a valid option.");
                                    scanner.nextLine();
                                    continue;
                                }
                            }
                        }

                        System.out.print("Chose an attribute to add points: ");
                        attributeOption = Character.toUpperCase(scanner.next().charAt(0));
                        scanner.nextLine();

                        switch (attributeOption) {
                            case 'C' -> {
                                int constituitionAdd;
                                ClearConsole.clear();
                                System.out.print("Points for constituition: ");
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
                            case 'A' -> {
                                int agilityAdd;
                                ClearConsole.clear();
                                System.out.print("Points for agility: ");
                                agilityAdd = scanner.nextInt();
                                agility = agilityAdd >= 0 ? agilityAdd : agility;
                                scanner.nextLine();
                                
                                if(agilityAdd >= 0){
                                    attributePoints -= agility;
                                }
                                else{
                                    ClearConsole.clear();
                                    System.out.print("You can't remove points. If you want to redistribute, use all your points first.");
                                    scanner.nextLine();
                                }
                            }
                            case 'S' -> {
                                int strengthAdd;
                                ClearConsole.clear();
                                System.out.print("Points for strength: ");
                                strengthAdd = scanner.nextInt();
                                strength = strengthAdd >= 0 ? strengthAdd : strength;
                                scanner.nextLine();
                                
                                if(strengthAdd >= 0){
                                    attributePoints -= strength;
                                }
                                else{
                                    ClearConsole.clear();
                                    System.out.print("You can't remove points. If you want to redistribute, use all your points first.");
                                    scanner.nextLine();
                                }
                            }
                            case 'D' -> {
                                int dexterityAdd;
                                ClearConsole.clear();
                                System.out.print("Points for dexterity: ");
                                dexterityAdd = scanner.nextInt();
                                dexterity = dexterityAdd >= 0 ? dexterityAdd : dexterity;
                                scanner.nextLine();

                                if(dexterityAdd >= 0){
                                    attributePoints -= dexterity;
                                }
                                else{
                                    ClearConsole.clear();
                                    System.out.println("You can't remove points. If you want to redistribute, use all your points first.");
                                    scanner.nextLine();
                                }
                            }
                            default -> {
                                ClearConsole.clear();
                                System.out.print("Select a valid option.");
                                scanner.nextLine();
                            }
                        }
                    }
                    scanner.nextLine();
                    
                    //Rolls D6 for defining player HP
                    hp += random.nextInt(6) + 1;
                    hp += random.nextInt(6) + 1;
                    hp += random.nextInt(6) + 1;
                    hp += constuition;
                    
                    player.setAgility(agility);
                    player.setConstuition(constuition);
                    player.setMaxHP(hp);
                    player.setHp(hp);
                    player.setName(name);
                    player.setStrength(strength);
                    player.setDexterity(dexterity);
                    player.updateArmor(bananeira);
                    // player.showDetails();
                    // scanner.nextLine();
                    
                    char inGameOption;
                    char weaponOption;
                    
                    //Attribute declaration of Giras, THE mage
                    girasTheMage.setName("Giras, THE mage");
                    girasTheMage.setHp(20);
                    girasTheMage.setMaxHP(girasTheMage.getHp());
                    girasTheMage.setDamage(3);
                    girasTheMage.setDefense(2);
                    girasTheMage.setAgility(0);
                    girasTheMage.setAggressivity(5);
                    girasTheMage.setDefensibility(3);
                    girasTheMage.setCurability(2);
                    
                    weaponCategorySelection:
                    while(true){
                        ClearConsole.clear();

                        Sprites.girasTheMage();

                        System.out.println("Hello, I'm Giras, the mage. I'm here to help you to");
                        System.out.println("understand about the game mechanics!");
                        System.out.println("First, you have to chose a weapon.");
                        System.out.println("--------------------------------\n");
                        System.out.println("> Heavy sword (H):");
                        System.out.println("  * Base damage: 8");
                        System.out.println("  * The damage of this weapon can be improved depending");
                        System.out.println("    of your strength\n");

                        System.out.println("> Dagger (D):");
                        System.out.println("  * Base damage: 4");
                        System.out.println("  * The damage of this weapon can be improved depending");
                        System.out.println("    of your dexterity");

                        System.out.print("Chose your weapon category: ");
                        weaponOption = Character.toUpperCase(scanner.next().charAt(0));
                        scanner.nextLine();

                        switch(weaponOption){
                            case 'D' -> {
                                player.updateWeapon(dagger);
                                break weaponCategorySelection;
                            }
                            case 'H' -> {
                                player.updateWeapon(heavySword);
                                break weaponCategorySelection;
                            }
                            default -> {
                                ClearConsole.clear();
                                System.out.print("Select a valid option.");
                                scanner.nextLine();
                            }
                        }   
                    }

                //     ClearConsole.clear();
                //    Sprites.girasTheMage();

                //    System.out.println("Now, try to attack me.");
                //    scanner.nextLine();
                    
                //     teachingAttack:
                //     while(girasTheMage.getHp() > 0){
                //         ClearConsole.clear();
                        
                //         System.out.println("--------------------------------");
                //         System.out.println("You are facing a Giras.\n");
                //         System.out.println("Name: " + girasTheMage.getName());
                //         System.out.println("HP: " + girasTheMage.getHp());

                //         Sprites.girasTheMage();

                //         System.out.println("--------------------------------");
                        
                //         System.out.println("HP: " + player.getHp());
                //         System.out.println("Attack (A) Defense (D) Use potion (P)");
                //         System.out.print("What do you want to do?: ");
                //         inGameOption = Character.toUpperCase(scanner.next().charAt(0));
                //         scanner.nextLine();
                        
                //         switch(inGameOption){
                //             case 'A' -> {
                //                 player.attack(girasTheMage);
                //                 break teachingAttack;
                //             }
                //             default -> {
                //                 ClearConsole.clear();

                //                Sprites.girasTheMage();

                //                 System.out.print("Press \"a\" to attack me!");
                //                 scanner.nextLine();
                //                 continue;
                //             }
                //         }
                //     }    

                //     while(true){
                //         ClearConsole.clear();
                //         Sprites.girasTheMage();

                //         System.out.print("Now, it's my turn.");
                //         scanner.nextLine();

                //         girasTheMage.attack(player);

                //         ClearConsole.clear();
                        
                //         System.out.println("--------------------------------");

                //         System.out.println("===================================");
                //         System.out.println("|  Giras, THE mage, attacked you! |");
                //         System.out.println("===================================");

                //         System.out.println("You are facing a Giras.\n");
                //         System.out.println("Name: " + girasTheMage.getName());
                //         System.out.println("HP: " + girasTheMage.getHp());

                //         Sprites.girasTheMage();

                //         System.out.println("Try to use a potion to recover your life.");

                //         System.out.println("--------------------------------");
                        
                //         System.out.println("HP: " + player.getHp());
                //         System.out.println("Attack (A) Defense (D) Use potion (P)");
                //         System.out.print("What do you want to do?: ");
                //         inGameOption = Character.toUpperCase(scanner.next().charAt(0));
                        
                //         switch(inGameOption){
                //             case 'P' -> player.usePotion();
                //             default -> {
                //                 ClearConsole.clear();

                //                Sprites.girasTheMage();

                //                 System.out.print("Press \"p\" to use a potion!");
                //                 scanner.nextLine();
                //                 continue;
                //             }
                //         }
                        
                //         ClearConsole.clear();
                //         Sprites.girasTheMage();

                //         System.out.print("Now, it\'s my turn.");
                        // scanner.nextLine();
                //     }

                player.battle(girasTheMage);

                }
                case 'C' -> {
                    ClearConsole.clear();
                    System.out.println("\"Dungeon Claws\" was a game made by Leonardo Antonio Gomes dos Santos");
                    System.out.println("                and Jos� Victor Colino Gon�alves\n");
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
