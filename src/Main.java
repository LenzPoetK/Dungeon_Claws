
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
            option = Character.toUpperCase(scanner.next().charAt(0));
            scanner.nextLine();

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
                    
                    player.showDetails();
                    scanner.nextLine();
                    
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
                    System.out.println("                and José Victor Colino Gonçalves\n");

                    System.out.print("                   >> Press any key to return <<");
                    scanner.nextLine();
                }
                case 'E' -> {
                    ClearConsole.clear();
                    System.out.println("Sair");
                    break GAME;
                }
                default -> {
                    ClearConsole.clear();
                    System.out.print("Select a valid option.");
                    scanner.nextLine();
                }
            }
        }
        scanner.close();
    }
}
