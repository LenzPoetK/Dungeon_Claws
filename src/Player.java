import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;
;

public class Player {
    //PLAYER ATTRIBUTES
    private String name;  
    private int maxHP;
    private int hp;
    private int constuition;
    private int strength;
    private int agility;
    private int dexterity;
    private int defense;
    private Weapon weaponInUse;
    private Armor armorInUse;
    private int potionCount;
    private boolean isDefending;

    //PLAYER CONSTRUCTOR
    public Player(String name, int hp, int constuition, int strength, int agility, int dexterity){
        this.name = name;
        this.maxHP = hp;
        this.hp = hp;
        this.constuition = constuition;
        this.strength = strength;
        this.agility = agility;
        this.dexterity = dexterity;
    }

    public void checkDefending(){
        if(this.isDefending == true){
            isDefending = false;
            armorDefense();
        }
    }

    public void attack(Enemy enemy){
        Scanner scanner = new Scanner(System.in);
        int weaponDammage = weaponInUse.weaponTotalDammage();
        if (weaponInUse.getCategory().equals("Heavy")){
            //calculate actual dammage
            int realHeavyDammage = weaponDammage + (int) Math.ceil(1.5*strength) - enemy.getDefense();
            realHeavyDammage = realHeavyDammage > 0? realHeavyDammage: 0;
            enemy.setHp(
                enemy.getHp() - realHeavyDammage
            );

            System.out.println("\nYou dealt " + realHeavyDammage + " dammage!");
            scanner.nextLine();
        }
        if(weaponInUse.getCategory().equals("Light")){
            //calculate actual dammage
            int realLightDammage = weaponDammage + (int) Math.ceil(1.5*strength) - enemy.getDefense();
            realLightDammage = realLightDammage > 0? realLightDammage: 0;
            enemy.setHp(
                enemy.getHp() - realLightDammage
            );
            
            System.out.println("\nYou dealt " + realLightDammage + " dammage!");
            scanner.nextLine();
        }
    }

    public void defend(){
        armorDefense();
        setDefense(getDefense()*2);
    }

    public void armorDefense(){
        setDefense((int) Math.ceil(getCurrentArmor().getArmor() + getConstuition()*1.5));
    }

    public void playerTurn(Enemy enemy){
        playerTurn:
        while(true){
            Scanner scanner = new Scanner(System.in);
            char playerOption;
            ClearConsole.clear();

            System.out.println("--------------------------------");
            System.out.println("You are facing a Foe!\n");
            System.out.println("Name: " + enemy.getName());
            System.out.println("HP: " + enemy.getHp());
            System.out.print(enemy.sprite);
            System.out.println("--------------------------------");
            
            System.out.println("HP: " + getHp());
            System.out.println("Potions Left: " + getPotionCount());
            System.out.println("Attack (A) Defense (D) Use potion (P)");
            System.out.print("What do you want to do?: ");
            playerOption = Character.toUpperCase(scanner.next().charAt(0));
            scanner.nextLine();

            switch(playerOption){
                case 'A' -> {
                    attack(enemy);
                    break playerTurn;
                }
                case 'D' -> {
                    defend();
                    break playerTurn;
                }
                case 'P' -> {
                    if (potionCount >0) {
                        usePotion();
                        potionCount -=1;
                        break playerTurn;
                    } else {
                        ClearConsole.clear();
                        System.out.println("you are out of potions");
                        scanner.nextLine();
                        continue playerTurn; 
                    }
                }
                default -> {
                    System.out.println("Select a valid option.");
                    continue;
                }
            }
        }
    }

    public void battle(Enemy enemy){
        potionCount = 3;
       while(getHp() > 0 && enemy.getHp() > 0){
            if(agility > enemy.getAgility()){
                checkDefending();
                enemy.checkDefending();

                playerTurn(enemy);
                enemy.enemyTurn(this);
            }
            else{
                checkDefending();
                enemy.checkDefending();

                enemy.enemyTurn(this);
                playerTurn(enemy);
            }
            if (getHp() <= 0) {
                Main.gameOver();
            }
       }
    }

    //FUNCTION
    public void usePotion(){
        int cure;
        cure = Potion.healingValue();

        if(hp == maxHP){
            Scanner input = new Scanner(System.in);
            
            ClearConsole.clear();

            System.out.print("Your HP is full!");
            input.nextLine();
        }
        else if(cure + getHp() > maxHP){
            hp = maxHP;
        }
        else{
            hp += cure;
        }
    }

    //FUNCTION
    public void showDetails(){
        System.out.println("Name: " + this.name);
        System.out.println("HP: " + this.hp);
        System.out.println("Constituition: " + this.constuition);
        System.out.println("Strength: " + this.strength);
        System.out.println("Agility: " + this.agility);
        System.out.println("Dexterity: " + this.dexterity);
    }

    public void levelUp(int points) {
        Scanner player_scanner = new Scanner(System.in);

        char playerOption;
        int availablePoints = points+1-1;
        int backupConstitution = this.getConstuition()+1-1;
        int backupAgility = this.getAgility()+1-1;
        int backupStrength = this.getStrength()+1-1;
        int backupDexterity = this.getDexterity()+1-1;

        while (availablePoints>0) {
            ClearConsole.clear();

            System.out.println("Adventurer " + getName() +  ", you have " + availablePoints + " points to distribute on:");
            System.out.println("> Constitution (C): " + constuition);
            System.out.println("> Strength (S): " + strength);
            System.out.println("> Agility (A): " + agility);
            System.out.println("> Dexterity (D): " + dexterity);
            System.out.print("\nChoose the attribute you would like to add points to: ");
            playerOption = Character.toUpperCase(player_scanner.next().charAt(0));
            player_scanner.nextLine();

            int pointsToAdd;

            switch (playerOption) {
                case 'C' -> {
                    //constitution
                    ClearConsole.clear();
                    pointsToAdd = recievePointsFromPlayer("Constitution", availablePoints);
                    availablePoints -= pointsToAdd;
                    setConstuition(getConstuition()+pointsToAdd);
                }
                case 'S' -> {
                    //strength
                    ClearConsole.clear();
                    pointsToAdd = recievePointsFromPlayer("Strength", availablePoints);
                    availablePoints -= pointsToAdd;
                    setStrength(getStrength()+pointsToAdd);
                }
                case 'A' -> {
                    //Agility
                    ClearConsole.clear();
                    pointsToAdd = recievePointsFromPlayer("Agility", availablePoints);
                    availablePoints -= pointsToAdd;
                    setAgility(getAgility()+pointsToAdd);
                }
                case 'D' -> {
                    //Dexterity
                    ClearConsole.clear();
                    pointsToAdd = recievePointsFromPlayer("Dexterity", availablePoints);
                    availablePoints -= pointsToAdd;
                    setDexterity(getDexterity()+pointsToAdd);
                }
            }
        }
        ClearConsole.clear();

        System.out.println("> Name: " + this.name);
        System.out.println("> Constituition: " + this.constuition);
        System.out.println("> Strength: " + this.strength);
        System.out.println("> Agility: " + this.agility);
        System.out.println("> Dexterity: " + this.dexterity);
        System.out.println("\nYes (Y)  No (N), redo\n");
        System.out.print("Are you happy with your choices?: ");
        playerOption = Character.toUpperCase(player_scanner.nextLine().charAt(0));

        switch (playerOption) {
            case 'Y' -> {
                break;
            }
            case 'N' -> {
                setAgility(backupAgility);
                setConstuition(backupConstitution);
                setDexterity(backupDexterity);
                setStrength(backupStrength);
                levelUp(points);
            }
            default -> {
                ClearConsole.clear();
                System.out.print("Select a valid option.");
                player_scanner.nextLine();
                levelUp(0);
            }
        }

        if (hp == 0) {
            setHp(initialHpCalc(getConstuition()));
            setMaxHP(getHp());
        }
        else
        {
            setHp(getHp() + getConstuition());
        }
    }

    private int recievePointsFromPlayer(String attribute, int availablePoints){
        int pointsToAdd;
        Scanner pointsFromPlayerScanner = new Scanner(System.in);

        while (true){
            System.out.print("How many points will you add to " + attribute + ": ");
            try {
                pointsToAdd = pointsFromPlayerScanner.nextInt();
            } catch (InputMismatchException e) {
                System.out.print("Type a number, please");
                pointsToAdd = 0;
                pointsFromPlayerScanner.nextLine();
            }
            if (pointsToAdd > availablePoints || pointsToAdd < 0) {
                ClearConsole.clear();
                System.out.println("You must enter a valid number (no negatives or more than available points).");
                System.out.println("Tip: if you want to redo your attributes, use all of them up first.");
            }
            else {
                break;
            }
        }
        return pointsToAdd;
    }

    private int initialHpCalc(int constitution){
        Random random = new Random();
        //gets random numbers from 0-5 three times, then adds 3 at the end to make it from 1-6
        return random.nextInt(6) + random.nextInt(6) + random.nextInt(6) + constitution + 3;
    }

    public Armor getCurrentArmor(){
        return this.armorInUse;
    }

    public void updateArmor(Armor newArmor){
        this.armorInUse = newArmor;
        armorDefense();
    }

    public Weapon getCurrentWeapon() {
        return this.weaponInUse;
    }

    public void updateWeapon(Weapon newWeapon) {
        this.weaponInUse = newWeapon;
    }

    public int getDexterity() {
        return dexterity;
    }

    public void setDexterity(int dexterity) {
        if(dexterity >= 0)
            this.dexterity = dexterity;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if(name.length() > 0)
            this.name = name;
    }

    public int getHp() {
        return hp;
    }

    public int getPotionCount() {
        return potionCount;
    }

    public void setPotionCount(int potionCount) {
        this.potionCount = potionCount;
    }

    public void setHp(int hp) {
        this.hp = hp;
        this.hp = hp;
    }

    public int getMaxHP() {
        return maxHP;
    }

    public void setMaxHP(int maxHP) {
        this.maxHP = maxHP;
    }

    public int getConstuition() {
        return constuition;
    }

    public void setConstuition(int constuition) {
        if(constuition >= 0)
            this.constuition = constuition;
    }

    public int getStrength() {
        return strength;
    }

    public void setStrength(int strength) {
        if(strength >= 0)
            this.strength = strength;
    }

    public int getAgility() {
        return agility;
    }

    public void setAgility(int agility) {
        if(agility >= 0)
            this.agility = agility;
    }

    public int getDefense() {
        return defense;
    }

    public void setDefense(int defense) {
        this.defense = defense;
    }

}
