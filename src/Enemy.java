public class Enemy {
    private String name;
    private int hp;
    private int damage;
    private int defense;
    private int agility;
    private int potionCount;

    public Enemy(int agility, int damage, int defense, int hp, String name, int potionCount) {
        this.agility = agility;
        this.damage = damage;
        this.defense = defense;
        this.hp = hp;
        this.name = name;
        this.potionCount = potionCount;
    }

    public int getPotionCount() {
        return potionCount;
    }

    public void setPotionCount(int potionCount) {
        if (potionCount > 0) 
            this.potionCount = potionCount;
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

    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        if(damage >= 0)
            this.damage = damage;
    }

    public int getDefense() {
        return defense;
    }

    public void setDefense(int defense) {
        if(defense >= 0)
            this.defense = defense;
    }

    public int getAgility() {
        return agility;
    }

    public void setAgility(int agility) {
        if(agility >= 0)
            this.agility = agility;
    }


    
}
