
import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
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
        Weapon dagger = new Weapon("Light", 4);
        Weapon heavySword = new Weapon("Heavy", 8);
        Weapon spear = new Weapon("light", 6);
        Weapon battleAxe = new Weapon("Heavy", 12);
        Weapon excalibur = new Weapon("Heavy", 15);
        Weapon dirk = new Weapon("Light", 9);
        Armor bananeira = new Armor(2);
        Armor chainPlate = new Armor(4);
        Armor peasentCloths = new Armor(1);
        Armor militarySuit = new Armor(6);
        Armor ironPlate = new Armor(5);
        Armor diamondPlate = new Armor(10);
        
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
                    while (true){
                        System.out.print("Enter your adventurer's name: ");
                        name = scanner.nextLine();
                        if (name.length() > 0){
                            player.setName(name);
                            break;
                        }else{
                            player.setName("Guest");
                            break;
                        }
                    }
                    
                    //levelUP is just a attribute distribution for the player
                    player.levelUp(attributePoints);
                    
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
                        System.out.println("    of your dexterity\n");
                        System.out.println("> Spear (S):");
                        System.out.println("  * Base damage: 6");
                        System.out.println("  * The damage of this weapon can be improved depending");
                        System.out.println("    of your dexterity\n");

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
                            case 'S' -> {
                                player.updateWeapon(spear);
                                break weaponCategorySelection;
                            }
                            default -> {
                                ClearConsole.clear();
                                System.out.print("Select a valid option.");
                                scanner.nextLine();
                            }
                        }   
                    }

                    armorCategorySelection:
                    while(true){
                        ClearConsole.clear();
    
                        Sprites.girasTheMage();
    
                        System.out.println("You have to chose an armor too.");
                        System.out.println("--------------------------------\n");
                        System.out.println("> Bananeira (B):");
                        System.out.println("  * Base defense: 2\n");
    
                        System.out.println("> Chain plate (C):");
                        System.out.println("  * Base defense: 4\n");
                    
                        System.out.println("> Peasent cloths (P):");
                        System.out.println("  * Base defense: 1\n");
    
                        System.out.print("Chose your armor: ");
                        weaponOption = Character.toUpperCase(scanner.next().charAt(0));
                        scanner.nextLine();
    
                        switch(weaponOption){
                            case 'B' -> {
                                player.updateArmor(bananeira);
                                break armorCategorySelection;
                            }
                            case 'C' -> {
                                player.updateArmor(chainPlate);
                                break armorCategorySelection;
                            }
                            case 'P' -> {
                                player.updateArmor(peasentCloths);
                                break armorCategorySelection;
                            }
                            default -> {
                                ClearConsole.clear();
                                System.out.print("Select a valid option.");
                                scanner.nextLine();
                            }
                        }   
                    }

                    ClearConsole.clear();
                   Sprites.girasTheMage();

                   System.out.println("Now, try to attack me.");
                   scanner.nextLine();
                    
                    teachingAttack:
                    while(girasTheMage.getHp() > 0){
                        ClearConsole.clear();
                        
                        System.out.println("--------------------------------");
                        System.out.println("You are facing a Giras.\n");
                        System.out.println("Name: " + girasTheMage.getName());
                        System.out.println("HP: " + girasTheMage.getHp());

                        Sprites.girasTheMage();

                        System.out.println("--------------------------------");
                        
                        System.out.println("HP: " + player.getHp());
                        System.out.println("Attack (A) Defense (D) Use potion (P)");
                        System.out.print("What do you want to do?: ");
                        inGameOption = Character.toUpperCase(scanner.next().charAt(0));
                        scanner.nextLine();
                        
                        switch(inGameOption){
                            case 'A' -> {
                                player.attack(girasTheMage);
                                break teachingAttack;
                            }
                            default -> {
                                ClearConsole.clear();

                               Sprites.girasTheMage();

                                System.out.print("Press \"a\" to attack me!");
                                scanner.nextLine();
                                continue;
                            }
                        }
                    }    

                    OUTER:
                    while(true){
                        ClearConsole.clear();
                        Sprites.girasTheMage();

                        System.out.print("Now, it's my turn.");
                        scanner.nextLine();

                        girasTheMage.attack(player);

                        ClearConsole.clear();
                        
                        System.out.println("--------------------------------");

                        System.out.println("===================================");
                        System.out.println("|  Giras, THE mage, attacked you! |");
                        System.out.println("===================================");

                        System.out.println("You are facing a Giras.\n");
                        System.out.println("Name: " + girasTheMage.getName());
                        System.out.println("HP: " + girasTheMage.getHp());

                        Sprites.girasTheMage();

                        System.out.println("Try to use a potion to recover your life.");

                        System.out.println("--------------------------------");
                        
                        System.out.println("HP: " + player.getHp());
                        System.out.println("Attack (A) Defense (D) Use potion (P)");
                        System.out.print("What do you want to do?: ");
                        inGameOption = Character.toUpperCase(scanner.next().charAt(0));
                        
                        switch(inGameOption){
                            case 'P' -> {
                                player.usePotion();
                                break OUTER;
                            }
                            default -> {
                                ClearConsole.clear();

                               Sprites.girasTheMage();

                                System.out.print("Press \"p\" to use a potion!");
                                scanner.nextLine();
                                continue;
                            }
                        }
                        
                    }
                    
                

                }
                case 'C' -> {
                    ClearConsole.clear();
                    System.out.println("\"Dungeon Claws\" was a game made by Leonardo Antonio Gomes dos Santos");
                    System.out.println("                and Jose Victor Colino Goncalves\n");
                }
                case 'E' -> {
                    ClearConsole.clear();
                    System.out.println("Sair");
                    break GAME;
                }
            }  
        }

        firstRandomBattle(player);

        weaponCategorySelection:
        while(true){
            char weaponOption;
            ClearConsole.clear();

            Sprites.girasTheMage();

            System.out.println("--------------------------------\n");
            System.out.println("> Battle axe (B):");
            System.out.println("  * Base damage: 12");
            System.out.println("  * The damage of this weapon can be improved depending");
            System.out.println("    of your strength\n");

            System.out.println("> Excalibur (E):");
            System.out.println("  * Base damage: 15");
            System.out.println("  * The damage of this weapon can be improved depending");
            System.out.println("    of your strength\n");

            System.out.println("> Durk (D):");
            System.out.println("  * Base damage: 9");
            System.out.println("  * The damage of this weapon can be improved depending");
            System.out.println("    of your dexterity\n");

            System.out.print("Chose your weapon category: ");
            weaponOption = Character.toUpperCase(scanner.next().charAt(0));
            scanner.nextLine();

            switch(weaponOption){
                case 'D' -> {
                    player.updateWeapon(dirk);
                    break weaponCategorySelection;
                }
                case 'E' -> {
                    player.updateWeapon(excalibur);
                    break weaponCategorySelection;
                }
                case 'B' -> {
                    player.updateWeapon(battleAxe);
                    break weaponCategorySelection;
                }
                default -> {
                    ClearConsole.clear();
                    System.out.print("Select a valid option.");
                    scanner.nextLine();
                }
            }   
        }

        player.levelUp(5);

        secondRandomBattle(player);

        armorCategorySelection:
        while(true){
            char armorOption;
            ClearConsole.clear();

            Sprites.girasTheMage();

            System.out.println("You have to chose an armor too.");
            System.out.println("--------------------------------\n");
            System.out.println("> Military suit (M):");
            System.out.println("  * Base defense: 6\n");

            System.out.println("> Iron plate (I):");
            System.out.println("  * Base defense: 5\n");
        
            System.out.println("> Diamond plate (D):");
            System.out.println("  * Base defense: 10\n");

            System.out.print("Chose your armor: ");
            armorOption = Character.toUpperCase(scanner.next().charAt(0));
            scanner.nextLine();

            switch(armorOption){
                case 'M' -> {
                    player.updateArmor(militarySuit);
                    break armorCategorySelection;
                }
                case 'I' -> {
                    player.updateArmor(ironPlate);
                    break armorCategorySelection;
                }
                case 'D' -> {
                    player.updateArmor(diamondPlate);
                    break armorCategorySelection;
                }
                default -> {
                    ClearConsole.clear();
                    System.out.print("Select a valid option.");
                    scanner.nextLine();
                }
            }   
        }

        player.levelUp(10);

        thirdRandomBattle(player);
        scanner.close();
    }

    private static void firstRandomBattle(Player player) {
        Random random = new Random();
        Enemy redGoblin = new Enemy(2, 5, 2, 15, "Red Goblin", 1, 3, 2, 1);
        Enemy greenGoblin = new Enemy(2, 5, 2, 15, "Green Goblin", 3, 1, 2, 3);
        Enemy blueGoblin = new Enemy(2, 5, 2, 15, "Blue Goblin", 2, 2, 3, 1);

        int randomEnemyChoice = random.nextInt(3);

        switch (randomEnemyChoice) {
            case 0:
                player.battle(redGoblin);
                break;
            case 1:
                player.battle(greenGoblin);
                break;
            case 2:
                player.battle(blueGoblin);
        }
    }

    private static void secondRandomBattle(Player player){
        Random random = new Random();
        Enemy redOrc = new Enemy(2, 5, 2, 15, "Red Orc", 2, 5, 2, 2);
        Enemy blueOrc = new Enemy(2, 5, 2, 15, "blue Orc", 2, 3, 4, 2);

        int randomEnemyChoice = random.nextInt(3);

        switch (randomEnemyChoice) {
            case 0:
                player.battle(redOrc);
                break;
            case 1:
                player.battle(blueOrc);
                break;
            case 2:
        }
    }
    private static void thirdRandomBattle(Player player){
        Enemy redDragon = new Enemy(10, 10, 10, 30, "Red Dragon", 3, 1, 1, 1);

        player.battle(redDragon);
    }
}
