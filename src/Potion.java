import java.util.Random;

public class Potion {
    public static int healingValue(){
        Random random = new Random();

        int healingValue = 0;

        for(int i = 0; i < 3; i++){
            healingValue += random.nextInt(6) + 1;
        }
        return healingValue;
    }
}
