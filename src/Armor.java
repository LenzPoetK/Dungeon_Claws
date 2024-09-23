public class Armor {
    private int defense;

    public Armor(int defense){
        if(defense > 0)
            this.defense = defense;
    }

    public int getDefense() {
        return defense;
    }
}
