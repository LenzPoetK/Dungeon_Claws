
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
        Enemy girasTheMage = new Enemy(0, 0, 0, 0, null, 0, 0, 0, 0, null);
        Weapon dagger = new Weapon("Light", 4);
        Weapon heavySword = new Weapon("Heavy", 8);
        Weapon spear = new Weapon("light", 6);
        Weapon battleAxe = new Weapon("Heavy", 12);
        Weapon excalibur = new Weapon("Heavy", 15);
        Weapon dirk = new Weapon("Light", 9);
        Armor bananeira = new Armor(2);
        Armor chainPlate = new Armor(4);
        Armor peasentCloths = new Armor(1);
        Armor reinforced_steel = new Armor(6);
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
                    int attributePoints = 15;
                    String name;
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
                    
                    ClearConsole.clear();
                    System.out.println("\"" + name + "\" you say into the darkness,it was that easy to let go of everything");
                    System.out.println("You find yourself in a dark pit, nothing arround you, no one either");
                    System.out.println("no sound, no touch, no light, no temperature. Only void, only nothingness");
                    System.out.println("Time passes, minutes go by like seconds, then hours, then days, its maddening");
                    System.out.println("Only yourself to entertain, you become your own game to play, first comes the rules");
                    scanner.nextLine();


                    //levelUP is just a attribute distribution for the player
                    player.levelUp(attributePoints);
                    
                    // player.showDetails();
                    // scanner.nextLine();
                    
                    char inGameOption;
                    char weaponOption;
                    
                    //Attribute declaration of Giras, THE wise
                    girasTheMage.setName("Giras, THE wise");
                    girasTheMage.setHp(20);
                    girasTheMage.setMaxHP(girasTheMage.getHp());
                    girasTheMage.setDamage(3);
                    girasTheMage.setDefense(2);
                    girasTheMage.setAgility(0);
                    girasTheMage.setAggressivity(5);
                    girasTheMage.setDefensibility(3);
                    girasTheMage.setCurability(2);
                    girasTheMage.sprite = Sprites.girasTheMage;
                    
                    weaponCategorySelection:
                    while(true){
                        ClearConsole.clear();

                        System.out.print(Sprites.girasTheMage);

                        System.out.println("Hello, I'm Giras, the wise. I'm here to help you to");
                        System.out.println("understand about the mechanics!");
                        System.out.println("First, you have to choose a weapon.");
                        System.out.println("--------------------------------\n");
                        System.out.println("> Heavy sword (H):");
                        System.out.println("  * Base damage: 8");
                        System.out.println("  * scales with Strength\n");
                        

                        System.out.println("> Dagger (D):");
                        System.out.println("  * Base damage: 4");
                        System.out.println("  * scales with Dexterity\n");

                        System.out.println("> Spear (S):");
                        System.out.println("  * Base damage: 6");
                        System.out.println("  * scales with Dexterity\n");

                        System.out.print("Chose your weapon: ");
                        weaponOption = Character.toUpperCase(scanner.nextLine().charAt(0));

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
    
                        System.out.print(Sprites.girasTheMage);
    
                        System.out.println("You have to chose an armor too.");
                        System.out.println("--------------------------------\n");
                        System.out.println("> Bandana (B):");
                        System.out.println("  * Base defense: 2\n");
    
                        System.out.println("> Chain plate (C):");
                        System.out.println("  * Base defense: 4\n");
                    
                        System.out.println("> Peasent's clothes (P):");
                        System.out.println("  * Base defense: 1\n");
    
                        System.out.print("Chose your armor: ");
                        weaponOption = Character.toUpperCase(scanner.nextLine().charAt(0));
    
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
                   System.out.print(Sprites.girasTheMage);

                   System.out.println("Now, try to attack me.");
                   scanner.nextLine();
                    
                    teachingAttack:
                    while(girasTheMage.getHp() > 0){
                        ClearConsole.clear();
                        
                        System.out.println("--------------------------------");
                        System.out.println("You are facing a Giras.\n");
                        System.out.println("Name: " + girasTheMage.getName());
                        System.out.println("HP: " + girasTheMage.getHp());

                        System.out.print(Sprites.girasTheMage);

                        System.out.println("--------------------------------");
                        
                        System.out.println("HP: " + player.getHp());
                        System.out.println("Attack (A) Defense (D) Use potion (P)");
                        System.out.print("What do you want to do?: ");
                        inGameOption = Character.toUpperCase(scanner.nextLine().charAt(0));
                        
                        switch(inGameOption){
                            case 'A' -> {
                                player.attack(girasTheMage);
                                break teachingAttack;
                            }
                            default -> {
                                ClearConsole.clear();

                               System.out.print(Sprites.girasTheMage);

                                System.out.print("Press \"a\" to attack me!");
                                scanner.nextLine();
                                continue;
                            }
                        }
                    }    

                    while(true){
                        ClearConsole.clear();
                        System.out.print(Sprites.girasTheMage);

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

                        System.out.print(Sprites.girasTheMage);

                        System.out.println("Try to use a potion to recover your life.");

                        System.out.println("--------------------------------");
                        
                        System.out.println("HP: " + player.getHp());
                        System.out.println("Attack (A) Defense (D) Use potion (P)");
                        System.out.print("What do you want to do?: ");
                        inGameOption = Character.toUpperCase(scanner.nextLine().charAt(0));
                        
                        switch(inGameOption){
                            case 'P' -> {
                                player.usePotion();
                                break GAME;
                            }
                            default -> {
                                ClearConsole.clear();

                                System.out.print(Sprites.girasTheMage);

                                System.out.print("Press \"p\" to use a potion!");
                                scanner.nextLine();
                                continue;
                            }
                        }
                        
                    }

                }
                case 'H' -> {
                    ClearConsole.clear();
                    System.out.println("You are just a usual college kid, trying to get by semester after semester");
                    System.out.println("But one day you feel something calling after you, a darkness that seamed endless");
                    System.out.println("You tried to ignore it, you're the only one feeling it, clearly this couldnt be good");
                    System.out.println("Until it got too loud to disconsider, it became a voice promising everything");
                    System.out.println("you could ever want, money, fame, goals, PURPOSE. It finnally won");
                    System.out.println("sometimes you wonder what would've happened had you known there was no way back...");
                    scanner.nextLine();
                }
                case 'C' -> {
                    ClearConsole.clear();
                    System.out.println("\"Dungeon Claws\" was a game made by Leonardo Antonio Gomes dos Santos");
                    System.out.println("                and Jose Victor Colino Goncalves\n");
                    scanner.nextLine();
                }
                case 'E' -> {
                    ClearConsole.clear();
                    System.out.println("Sair");
                    System.exit(0);
                    break GAME;
                }
            }
        }
        ClearConsole.clear();
        System.out.println("The strange and glitterry figure vanishes before your eyes, without leaving a trace");
        System.out.println("now surrounded by trees, a vast scenery unfolds in front of you, full of color and life");
        System.out.println("'is this still just my own mind?' you ponder. But whatever this is, beats absolute nothing");
        scanner.nextLine();

        ClearConsole.clear();
        System.out.print(Sprites.castle);
        System.out.println("From afar, you can make the silhouette of a eerie castle");
        System.out.println("You entered this place out of desperation, but now all you seek");
        System.out.println("is a way out of this nightmare, and you will do whatever it takes");
        System.out.println("as you approach the rocky foundation, a group of creatures surrounds you!");
        System.out.println("\nThe bigger of them says:");
        System.out.println("   Ggive usSsS alll yoOuu Havve, OrRR DieEE!");
        System.out.println("\n you grip your weapon tight, that's not gonna happen without a fight.");
        scanner.nextLine();


        firstRandomBattle(player);

        ClearConsole.clear();
        System.out.println("You manage to defeat the fowl creature, and the others scatter as you do");
        System.out.println("They leave many items behind, most of them quite useles, but some...");
        System.out.println("A scary big axe that you doubt any of the little devils could even raise");
        System.out.println("The shiniest thing you've ever seen in this scary place, the Sword of legends");
        System.out.println("Lighter than even your clothes, a blade akin to a dagger, but a LOT deadlier");
        scanner.nextLine();

        weaponCategorySelection:
        while(true){
            char weaponOption;
            ClearConsole.clear();

            System.out.println("--------------------------------\n");
            System.out.println("> Battle axe (B):");
            System.out.println("  * Base damage: 12");
            System.out.println("  * scales with Strength\n");

            System.out.println("> Excalibur (E):");
            System.out.println("  * Base damage: 15");
            System.out.println("  * scales with Strength\n");

            System.out.println("> Dirk (D):");
            System.out.println("  * Base damage: 15");
            System.out.println("  * scales with Dexterity\n");

            System.out.println("--------------------------------\n");


            System.out.print("Chose your new weapon: ");
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

        ClearConsole.clear();
        System.out.println("After meticulously examining your options, you sense something...");
        System.out.println("Whatever this place is, it seams to change everything within it\n");
        System.out.println("And you are NOT an exception...\n");
        System.out.println("Even though you feel unsure about it, there's no mistaking it:");
        System.out.println("You've gotten stronger after succeding against your enemies");
        scanner.nextLine();

        player.levelUp(5);

        ClearConsole.clear();

        System.out.println("You get closer still to the castle walls, but when you finally ");
        System.out.println("Reach the gate leading to it, two Gigantic figures await you");
        System.out.println("They seam as strong as they are big, but you dont plan on backing down");
        System.out.println("One of them sees you and says in a slow, deep voice:\n");
        System.out.println("YOU... NO... ENTER...\n");
        System.out.println("The other slaps the first in the back of the head and says, slightly annoyed");
        System.out.println("I've told you not to speak with intruders, you dimwit");
        System.out.println("Now we have no choice BUT to kill him, at least try to make it quick");
        scanner.nextLine();

        secondRandomBattle(player);

        ClearConsole.clear();

        System.out.println("The giant falls to his feet, defeated and speachless");
        System.out.println("Whatever their duty was, you've just made it pointless");
        System.out.println("Entering the castle, a couple of statues are arranged");
        System.out.println("All of them wearing the most prestigious of vests and weapons");
        System.out.println("You try to take some swords to properly inspect");
        System.out.println("But the statues's grip is too firm, however their armory...");;
        scanner.nextLine();

        armorCategorySelection:
        while(true){
            char armorOption;
            ClearConsole.clear();

            System.out.println("choose an armor.");
            System.out.println("--------------------------------\n");
            System.out.println("> Reinforced steel plate (R):");
            System.out.println("  * Base defense: 6\n");

            System.out.println("> Iron plate (I):");
            System.out.println("  * Base defense: 5\n");
        
            System.out.println("> Diamond plate (D):");
            System.out.println("  * Base defense: 10\n");
            System.out.println("--------------------------------\n");


            System.out.print("Chose your armor: ");
            armorOption = Character.toUpperCase(scanner.next().charAt(0));
            scanner.nextLine();

            switch(armorOption){
                case 'R' -> {
                    player.updateArmor(reinforced_steel);
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

        ClearConsole.clear();

        System.out.println("That same feeling dominates you, and you're powerless to stop it");
        System.out.println("A powerfull force seems to control your movements and enter your body");
        System.out.println("It stops, you cant feel it, its inside now, but you feel something...");
        System.out.println("The Muscles, the sharpened reflexes, you've just gotten a LOT stronger");
        scanner.nextLine();

        player.levelUp(10);

        ClearConsole.clear();

        System.out.println("After getting used to this newfound power, you go further deep into the castle");
        System.out.println("You enter an open area in the middle of the engulfing architecture");
        System.out.println("First, you feel relieved from the narrow pathways of the castle, but then you see");
        System.out.println("The most terrifying beast of them all, siting right on the center");
        System.out.println("Bellow it, a mountain of treasure impossible to calculate, behind it, a door");
        System.out.println("'could it be the exit' you think, hopefull that there is a way out");
        System.out.println("Either way there's nowhere to go but trough this creature's lair\n");
        System.out.println("        The Red Dragon ROARS, as you step into its sight");
        scanner.nextLine();

        thirdRandomBattle(player);

        ClearConsole.clear();

        System.out.print(Sprites.dragonSilhouette);
        System.out.println("\nThe beast flies away, humiliated by your overwhelming triumph");
        System.out.println("Behind the incalculable piles of gold, the great door awaits you");
        System.out.println("'please be the exit please be the exit' you put all of your faith on those thoughts as you approach it");
        System.out.println("And with each step harder than the last, first you think its the fatigue from all the action");
        System.out.println("Soon you realize its the opposite, you feel revigorated, stronger than ever");
        System.out.println("You are right in front of the door, and when you reach out your hand to pull it open");
        System.out.println("It finally downs on you, the immense weight of all your struggle, its almost impossible to stand");
        System.out.println("All that keeps you standing is the strange feeling , now stronger than ever, you understand");
        System.out.println("The power you've gained here has made you weak, now even standing up without it is a challange");
        System.out.println("Only by staying here would this curse continue to support you, in fact, it would only grow, for as long as you are in\n");
        System.out.println("        THE DUNGEONS'S CLAWS\n\n\n");
        System.out.println("                GAME OVER");
        scanner.nextLine();

        scanner.close();
    }

    private static void firstRandomBattle(Player player) {
        Random random = new Random();
        Enemy redGoblin = new Enemy(2, 5, 2, 20, "Red Goblin", 1, 3, 2, 1, Sprites.goblin);
        Enemy greenGoblin = new Enemy(2, 5, 2, 20, "Green Goblin", 3, 1, 2, 3, Sprites.goblin);
        Enemy blueGoblin = new Enemy(2, 5, 2, 20, "Blue Goblin", 2, 2, 3, 1, Sprites.goblin);

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
        Enemy redOrc = new Enemy(2, 5, 2, 35, "Red Orc", 2, 5, 2, 2, Sprites.orc);
        Enemy blueOrc = new Enemy(2, 5, 2, 35, "blue Orc", 2, 3, 4, 2, Sprites.orc);

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
        Enemy redDragon = new Enemy(10, 10, 8, 50, "Red Dragon", 3, 1, 1, 1, Sprites.dragon);

        player.battle(redDragon);
    }

    public static void gameOver() {
        Scanner gameOverScanner = new Scanner(System.in);
        ClearConsole.clear();
        System.out.println("The Dungeon's Claws got the best of you");
        System.out.println("                GAME OVER");
        gameOverScanner.nextLine();
        main(null);
    }
}
