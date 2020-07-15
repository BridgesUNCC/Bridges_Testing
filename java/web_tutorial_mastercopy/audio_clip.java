import java.io.IOException;
import java.lang.Exception;

import bridges.connect.Bridges;
import bridges.validation.RateLimitException;
import bridges.base.AudioClip;

public class audio_clip {
	private static void generateSine(AudioClip ac) {
		for (int s = 0; s < ac.getSampleCount(); s++) {
			for (int c = 0; c < ac.getNumChannels(); c++) {
				double val = Math.sin(s /20.);
				
				ac.setSample(c, s, (int)(val * Integer.MAX_VALUE));
			}
		}
	}

//	public static void main(String[] args) throws IOException, WavFileException, RateLimitException {
	public static void main(String[] args) throws IOException, RateLimitException {
#if TESTING

        Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
        bridges.setServer(args[3]);


#else
        Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID",
            "YOUR_API_KEY");
#endif


	    bridges.setTitle("Audio Test");

            AudioClip ac = new AudioClip(44100*5, 1, 32, 44100);
	    
	    generateSine(ac);
	    
	    bridges.setDataStructure(ac);

	    bridges.visualize();


	    
	    AudioClip ac2 = new AudioClip("../../data/clap-8bit.wav");

	    bridges.setDataStructure(ac2);

	    bridges.visualize();

	    AudioClip ac3 = new AudioClip("../../data/clap-16bit.wav");
		
	    bridges.setDataStructure(ac3);

	    bridges.visualize();

	    AudioClip ac4 = new AudioClip("../../data/clap-24bit.wav");

	    
	    bridges.setDataStructure(ac4);

	    bridges.visualize();

	    
	    AudioClip ac5 = new AudioClip("../../data/clap-32bit.wav");
	    
	    bridges.setDataStructure(ac5);

		bridges.visualize();
	    
	}
}
