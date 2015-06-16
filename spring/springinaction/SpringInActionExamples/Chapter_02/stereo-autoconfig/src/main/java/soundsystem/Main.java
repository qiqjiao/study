package soundsystem;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;

@ContextConfiguration(classes=CDPlayerConfig.class)
public class Main {

  @Autowired
  private MediaPlayer player;
  
  @Autowired
  private CompactDisc cd;
  
  @Test
  public static void main(String[] args) {
    player.play();
  }

}
