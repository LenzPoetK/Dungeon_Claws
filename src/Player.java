public class Player {
    private String name;  
    private int hp;
    private int constuition;
    private int strength;
    private int agility;

    public Player(String name, int hp, int constuition, int strength, int agility){
        this.name = name;
        this.hp = hp;
        this.constuition = constuition;
        this.strength = strength;
        this.agility = agility;
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
        if(hp > 0)
            this.hp = hp;
    }

    public int getConstuition() {
        return constuition;
    }

    public void setConstuition(int constuition) {
        if(constuition > 0)
            this.constuition = constuition;
    }

    public int getStrength() {
        return strength;
    }

    public void setStrength(int strength) {
        if(strength > 0)
            this.strength = strength;
    }

    public int getAgility() {
        return agility;
    }

    public void setAgility(int agility) {
        if(agility > 0)
            this.agility = agility;
    }

    public void showDetails(){
        System.out.println("Name: " + this.name);
        System.out.println("HP: " + this.hp);
        System.out.println("Constituition: " + this.constuition);
        System.out.println("Strength: " + this.strength);
        System.out.println("Agility: " + this.agility);
    }
}
