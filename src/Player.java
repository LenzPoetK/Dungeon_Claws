import java.util.Random;
import java.util.Scanner;

public class Player {
    private String name;  
    private int hp;
    private int constuition;
    private int strength;
    private int agility;
    private int dexterity;
    private Weapon weaponUsed;

    public Player(String name, int hp, int constuition, int strength, int agility, int dexterity){
        this.name = name;
        this.hp = hp;
        this.constuition = constuition;
        this.strength = strength;
        this.agility = agility;
        this.dexterity = dexterity;
    }

    public void levelUp(int points) {
        char playerOption;
        int availablePoints = points+1-1;
        Scanner player_scanner = new Scanner(System.in);
        ClearConsole.clear();
        //creating backup
        int backupConstitution = this.getConstuition()+1-1;
        int backupAgility = this.getAgility()+1-1;
        int backupStrength = this.getStrength()+1-1;
        int backupDexterity = this.getDexterity()+1-1;
        while (availablePoints>0) {
            
            System.out.println("Adventurer " + getName() +  ", you have " + availablePoints + " points to distribute on:");
            System.out.println("(C)onstitution: " + constuition);
            System.out.println("(S)trength: " + strength);
            System.out.println("(A)gility: " + agility);
            System.out.println("(D)exterity: " + dexterity);
            System.out.println("\nChoose the attribute you would like to add points to: ");
            playerOption = Character.toUpperCase(player_scanner.next().charAt(0));
            int pointsToAdd;

            switch (playerOption) {
                case 'C':
                    //constitution
                    ClearConsole.clear();
                    pointsToAdd = recievePointsFromPlayer("Constitution", availablePoints);
                    availablePoints -= pointsToAdd;
                    setConstuition(getConstuition()+pointsToAdd);
                    break;
                case 'S':
                    //strength
                    ClearConsole.clear();
                    pointsToAdd = recievePointsFromPlayer("Strength", availablePoints);
                    availablePoints -= pointsToAdd;
                    setStrength(getStrength()+pointsToAdd);
                    break;
                case 'A':
                    //Agility
                    ClearConsole.clear();
                    pointsToAdd = recievePointsFromPlayer("Agility", availablePoints);
                    availablePoints -= pointsToAdd;
                    setAgility(getAgility()+pointsToAdd);
                    break;
                case 'D':
                    //Dexterity
                    ClearConsole.clear();
                    pointsToAdd = recievePointsFromPlayer("Dexterity", availablePoints);
                    availablePoints -= pointsToAdd;
                    setDexterity(getDexterity()+pointsToAdd);
                    break;
            }

            setHp(initialHpCalc(getConstuition()));
        }

        System.out.println("Name: " + this.name);
        System.out.println("Constituition: " + this.constuition);
        System.out.println("Strength: " + this.strength);
        System.out.println("Agility: " + this.agility);
        System.out.println("Dexterity: " + this.dexterity);
        System.out.println("\nAre you happy with your choices?");
        System.out.println("(Y)es (N)o, redo");
        player_scanner.nextLine();
        playerOption = Character.toUpperCase(player_scanner.nextLine().charAt(0));
        if (playerOption == 'Y') {
            return;
        }
        else if (playerOption == 'N') {
            setAgility(backupAgility);
            setConstuition(backupConstitution);
            setDexterity(backupDexterity);
            setStrength(backupStrength);
            levelUp(points);
        }
        else {
            ClearConsole.clear();
            System.out.println("Select a valid option");
            player_scanner.nextLine();
            levelUp(0);
        }
    }

    private int recievePointsFromPlayer(String attribute, int availablePoints){
        int pointsToAdd;
        Scanner pointsFromPlayerScanner = new Scanner(System.in);
        while (true){
            System.out.println("How many points will you add to " + attribute + ": ");
            pointsToAdd = pointsFromPlayerScanner.nextInt();
            if (pointsToAdd > availablePoints || pointsToAdd < 0) {
                ClearConsole.clear();
                System.out.println("You must enter a valid number (no negatives or more than available points).");
                System.out.println("Tip: if you want to redo your attributes, use all of them up first.");
                continue;
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

    

    public int getDexterity() {
        return dexterity;
    }

    public void setDexterity(int dexterity) {
        this.dexterity = dexterity;
        
    }

    public Weapon getCurrentWeapon() {
        return this.weaponUsed;
    }

    public void updateWeapon(Weapon newWeapon) {
        this.weaponUsed = newWeapon;
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

    public void setHp(int hp) {
        this.hp = hp;
    }

    public int getConstuition() {
        return constuition;
    }

    public void setConstuition(int constuition) {
        this.constuition = constuition;
    }

    public int getStrength() {
        return strength;
    }

    public void setStrength(int strength) {
        this.strength = strength;
    }

    public int getAgility() {
        return agility;
    }

    public void setAgility(int agility) {
        this.agility = agility;
    }

    public void showDetails(){
        System.out.println("HP: " + hp);
        System.out.println("Constituition: " + constuition);
        System.out.println("Strength: " + strength);
        System.out.println("Agility: " + agility);
        System.out.println("Dexterity: " + dexterity);
    }
}
