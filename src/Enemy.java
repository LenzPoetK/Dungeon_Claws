public class Enemy {
    private String name;
    private int hp;
    private int damage;
    private int defense;
    private int agility;

    public Enemy(int agility, int damage, int defense, int hp, String name) {
        setName(name);
        setAgility(agility);
        setDamage(damage);
        setDefense(defense);
        setHp(hp);
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
