import java.util.Random;
public class Enemy {
    private String name;
    private int hp;
    private int maxHP;
    private int damage;
    private int defense;
    private int agility;
    private int potionCount;
    private int aggressivity;
    private int defensibility;
    private int curability;
    private boolean isDefending;
    public String sprite;

    public Enemy(int agility, int damage, int defense, int hp, String name, int potionCount, int aggressivity, int defensibility, int curability, String sprite) {
        this.agility = agility;
        this.damage = damage;
        this.defense = defense;
        this.hp = hp;
        this.maxHP = 1+hp-1;
        this.name = name;
        this.potionCount = potionCount;
        this.aggressivity = aggressivity;
        this.defensibility = defensibility;
        this.curability = curability;
        this.sprite = sprite;
    }

    public int totalSum(){
        return this.getAggressivity()+this.getDefensibility()+this.getCurability();
    }

    public void enemyTurn(Player player){
        Random random = new Random();
        int enemyPossiblity = random.nextInt(totalSum());

        if(enemyPossiblity < getAggressivity()){
            attack(player);
        }
        else if(enemyPossiblity >= getAggressivity() && enemyPossiblity < getAggressivity()+getDefensibility()){
            defend();
        }
        else if(enemyPossiblity >= getAggressivity()+getDefensibility()){
            usePotion();
        }
    }

    public void checkDefending(){
        if(this.isDefending == true){
            isDefending = false;
            setDefense(getDefense()/2);
        }
    }

    public void defend(){
        isDefending = true;
        setDefense(getDefense()*2);
    }

    public void attack(Player player){
        player.setHp(player.getHp() - damage);
    }
    
    public void usePotion(){
        int cure;
        cure = Potion.healingValue();

        if(cure + getHp() > maxHP){
            hp = maxHP;
        }
        else{
            hp += cure;
        }
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

    public int getAggressivity() {
        return aggressivity;
    }

    public void setAggressivity(int aggressivity) {
            this.aggressivity = aggressivity;
    }

    public int getDefensibility() {
        return defensibility;
    }

    public void setDefensibility(int defensibility) {
            this.defensibility = defensibility;
    }

    public int getCurability() {
        return curability;
    }

    public void setCurability(int curability) {
            this.curability = curability;
    }

    public int getMaxHP() {
        return maxHP;
    }

    public void setMaxHP(int maxHP) {
        this.maxHP = maxHP;
    }
}
