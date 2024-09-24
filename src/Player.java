
import java.util.Random;
import java.util.Scanner;

public class Player {
    //PLAYER ATTRIBUTES
    private String name;  
    private int maxHP;
    private int hp;
    private int constuition;
    private int strength;
    private int agility;
    private int dexterity;
    private Weapon weaponInUse;
    private Armor armorInUse;

    //PLAYER CONSTRUCTOR
    public Player(String name, int hp, int constuition, int strength, int agility, int dexterity){
        this.name = name;
        this.maxHP = hp;
        this.hp = maxHP;
        this.constuition = constuition;
        this.strength = strength;
        this.agility = agility;
        this.dexterity = dexterity;
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

    public void battle(Enemy enemy){
        if(getAgility() > enemy.getAgility()){

        }
        else if(getAgility() < enemy.getAgility()){
            Random random = new Random();
            int enemyOption = random.nextInt(5)+1;

            switch(enemyOption){
                case 1 -> enemy.attack(this);
                case 2 -> enemy.attack(this);
                case 3 -> enemy.attack(this);
                case 4 -> enemy.usePotion();
                case 5 -> enemy.attack(this);
            }
        }
    }

    //FUNCTION
    public void usePotion(){
        if(Potion.healingValue() + hp < maxHP){
            hp += Potion.healingValue();
        }
        else{
            Scanner input = new Scanner(System.in);

            ClearConsole.clear();
            System.out.print("Your HP is full!");
            input.nextLine();
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
        if(hp >= 0)
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

}
