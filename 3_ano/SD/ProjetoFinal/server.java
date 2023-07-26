import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

class ServerWorker implements Runnable {
    private Socket socket;
    ArrayList<String> locais = new ArrayList<>();
    MarList marList;

    public ServerWorker(Socket socket, ArrayList<String> locais, MarList marList) {
        this.socket = socket;
        this.locais = locais;
        this.marList = marList;
    }

    // @TODO
    @Override
    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            String line;

            while ((line = in.readLine()) != null) {
                String[] result = line.split(" ", 3);
                String command = result[0];
                String locall = "";
                int sns = 0;
                boolean validD = true;
                boolean validL = false;
                if (result.length == 2) {
                    sns = Integer.parseInt(result[1]);
                    if (sns < 100 || sns > 1000) {
                        validD = false;
                        out.println("Numero de Sns invalido");
                    }
                }
                if (result.length == 3) {
                    locall = result[1];
                    for (String loocal : locais) {
                        if (loocal.equals(locall)) {
                            validL = true;
                        }
                    }
                    if (validL == false) {
                        out.println("Local invalido");
                    }
                    sns = Integer.parseInt(result[2]);
                    if (sns < 100 || sns > 1000) {
                        validD = false;
                        out.println("Numero de Sns invalido");
                    }
                }
                if (command.equals("LOCAIS")) {
                    out.println(locais.toString());
                }
                if (command.equals("AGENDAR") && validL == true && validD == true) {
                    marList.addMarc(sns, locall);
                    marList.mostraa();
                    validD = false;
                    validL = false;
                }
                if (command.equals("DESMARCAR") && validD == true) {
                    marList.desmarcar(sns);
                    marList.mostraa();
                    validD = false;
                }
            }

            socket.shutdownOutput();
            socket.shutdownInput();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

public class server {

    public static void main(String[] args) throws IOException {

        ArrayList<String> locais = new ArrayList<>();
        MarList marList = new MarList();

        locais.add("Famalicao");
        locais.add("Guimaraes");
        locais.add("Braga");

        ServerSocket serverSocket = new ServerSocket(9998);

        while (true) {
            Socket socket = serverSocket.accept();
            System.out.println("Nova Conexao");
            Thread worker = new Thread(new ServerWorker(socket, locais, marList));
            worker.start();
        }
    }
}
