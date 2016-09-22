package exo3;



import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;



public class UdpHello {

	public static void main(String[] args) throws IOException {
		DatagramSocket socket = new DatagramSocket();
		InetSocketAddress dest = new InetSocketAddress("192.168.130.171", 20000);
		byte[] bufE = new String("Hello, world").getBytes();
		DatagramPacket dpE = new DatagramPacket(bufE, bufE.length, dest);
		socket.send(dpE);
		socket.close();
	}

}
