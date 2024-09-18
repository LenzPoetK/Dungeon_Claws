public class Enemy {
    private String name;
    private int hp;
    private int damage;
    private int defense;
    private int agility;

    public Enemy(int agility, int damage, int defense, int hp, String name) {
        this.agility = agility;
        this.damage = damage;
        this.defense = defense;
        this.hp = hp;
        this.name = name;
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

    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }

    public int getDefense() {
        return defense;
    }

    public void setDefense(int defense) {
        this.defense = defense;
    }

    public int getAgility() {
        return agility;
    }

    public void setAgility(int agility) {
        this.agility = agility;
    }


    
}
