
import java.util.Random;

public class Potion {
    public int usePotion(){
        Random random = new Random();

        int restoredLP = 0;

        for(int i = 0; i < 3; i++){
            restoredLP += random.nextInt(6) + 1;
            restoredLP += random.nextInt(6) + 1;
            restoredLP += random.nextInt(6) + 1;
        }
        return restoredLP;
    }
}
