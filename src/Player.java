
import java.util.Scanner;
;

public class Player {
    //PLAYER ATTRIBUTES
    private String name;  
    private int maxHP;
    private int hp;
    private int maxhp;
    private int constuition;
    private int strength;
    private int agility;
    private int dexterity;
    private int defense;
    private Weapon weaponInUse;
    private Armor armorInUse;
    public boolean isDefending;

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
            setDefense(getDefense()/2);
        }
    }

    public void attack(Enemy enemy){
        if (weaponInUse.getCategory().equals("Heavy")){
            enemy.setHp(
                enemy.getHp() - weaponInUse.getDamage() + (int) Math.ceil(1.5*strength)
            );
        }
        if(weaponInUse.getCategory().equals("Light")){
            enemy.setHp(
                enemy.getHp() - weaponInUse.getDamage() + dexterity
            );
        }
    }

    public void defend(){
        armorDefense();
        setDefense(getDefense()*2);
    }

    public void armorDefense(){
        setDefense((int) Math.ceil(getCurrentArmor().getArmor()*1.5));
    }

    public void playerTurn(Enemy enemy){
        playerTurn:
        while(true){
            Scanner scanner = new Scanner(System.in);
            char playerOption;
            ClearConsole.clear();

            System.out.println("--------------------------------");
            System.out.println("You are facing a Giras.\n");
            System.out.println("Name: " + enemy.getName());
            System.out.println("HP: " + enemy.getHp());
            Sprites.girasTheMage();
            System.out.println("--------------------------------");
            
            System.out.println("HP: " + getHp());
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
                    usePotion();
                    break playerTurn;
                }
                default -> {
                    System.out.println("Select a valid option.");
                    continue;
                }
            }
        }
    }

    public void battle(Enemy enemy){
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

    public Armor getCurrentArmor(){
        return this.armorInUse;
    }

    public void updateArmor(Armor newArmor){
        this.armorInUse = newArmor;
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
