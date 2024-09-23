import java.util.Random;

public class Weapon {
    private int damage;
    private String category;

    public Weapon(String category, int damage) {
        setCategory(category);
        setDamage(damage);
    }

    public float weaponTotalDammage(){
        Random random = new Random();
    
        //Heavy weapond deal 2d6 dammage + 1.5*playerStrength, 
        //here the method just rolls the d6, player influence is dealt with in player class
        if ("Heavy".equals(category)) {
            return random.nextInt(12)+1 + damage;
        }
        // Light weapons deal 2d6 + 1d4 dammage + playerDex, player influence... (you get it now)
        else if ("Light".equals(category)){
            return random.nextInt(6)+1 + random.nextInt(6)+1 + random.nextInt(4)+1 + damage;
        }
        else {
            return 0;
        }
    }

    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        if (damage >= 0)
            this.damage = damage;
    }
    
    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        if (category.length() > 0)
            this.category = category;
    }
}
