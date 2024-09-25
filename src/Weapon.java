import java.util.Random;

public class Weapon {
    public int damage;
    public String category;


    public float weaponTotalDammage(){
        Random random = new Random();
    
        //Heavy weapond deal 2d6 dammage + 1.5*playerStrength, 
        //here the method just rolls the d6, player influence is dealt with in player class
        if (category == "Heavy") {
            return random.nextInt(6)+1 + random.nextInt(6)+1;
        }
        // Light weapons deal 3d4 dammage + 1.5*playerDex, player influence... (you get it now)
        else if (category == "Light"){
            return random.nextInt(4)+1 + random.nextInt(4)+1 + random.nextInt(4)+1;
        }
        else {
            return 0;
        }
    }

    public Weapon(int damage, String category) {
        this.damage = damage;
        this.category = category;
    }

    public int getDamage() {
        return damage;
    }
    public void setDamage(int damage) {
        if (damage >= 0){
            this.damage = damage;
        }
    }
    public String getCategory() {
        return category;
    }
    public void setCategory(String category) {
        if (category.length() > 0){
            this.category = category;
        }
    }

    
}
