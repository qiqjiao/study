import java.io.*;
import java.util.logging.*;

class Test {
	public static void main(String[] args) {
		try {
			//Handler handler = new FileHandler("OutFile.log");
			//Logger.getLogger("").addHandler(handler);
			throw new IOException("heleo");

		} catch (IOException e) {
			Logger logger = Logger.getLogger("package.name");
			StackTraceElement elements[] = e.getStackTrace();
			for (int i = 0, n = elements.length; i < n; i++) {
				logger.log(Level.WARNING, elements[i].getMethodName());
			}
		}
	}

}
