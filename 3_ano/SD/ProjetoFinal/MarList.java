import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.concurrent.locks.ReentrantLock;

public class MarList {
    private static ArrayList<Marcacao> marcacoes;
    private static ReentrantLock lock;
    Calendar date;
    static Date DataInicial;

    public MarList() {
        marcacoes = new ArrayList<>();
        lock = new ReentrantLock();
        date = Calendar.getInstance();
        date.set(Calendar.HOUR_OF_DAY, 9);
        date.set(Calendar.MINUTE, 0);
        date.set(Calendar.SECOND, 0);
        date.set(Calendar.MILLISECOND, 0);
        long timeInSecs = date.getTimeInMillis();
        DataInicial = new Date(timeInSecs + (1440 * 60 * 1000));
    }

    public void addMarc(int sns, String locall) {
        lock.lock();
        Date DataUsar = new Date();
        boolean marc = false;
        int contador = 0;
        for (Marcacao marcacao : marcacoes) {
            if (marcacao.getLocal().equals(locall) && marcacao.getEstado().equals("Desmarcado")) {
                marcacao.setNSns(sns);
                marcacao.setEstado("Marcado");
                marc = true;
                break;
            }
        }
        if (marc == false) {
            if (marcacoes.size() == 0) {
                DataUsar.setTime(DataInicial.getTime() - (20 * 60 * 1000));
            }
            if (marcacoes.size() > 0) {
                for (Marcacao marcacao : marcacoes) {
                    if (marcacao.getLocal().equals(locall)) {
                        contador++;
                        if (DataUsar.compareTo(marcacao.getHora_marcacao()) < 0) {
                            DataUsar = marcacao.getHora_marcacao();
                        }
                    }
                }
                if (contador == 0) {
                    DataUsar.setTime(DataInicial.getTime() - (20 * 60 * 1000));
                }

            }
            try {
                Date ndate = new Date(DataUsar.getTime() + (20 * 60 * 1000));
                Marcacao m = new Marcacao(sns, locall, ndate, "Marcado");
                marcacoes.add(m);
            } finally {
                lock.unlock();
            }
        }
    }

    public void desmarcar(int sns) {
        lock.lock();
        try {
            for (Marcacao marcacao : marcacoes) {
                if (marcacao.getNSns() == sns) {
                    marcacao.setEstado("Desmarcado");
                    marcacao.setNSns(0);
                    System.out.println(marcacao.getEstado());
                }
            }
        } finally {
            lock.unlock();
        }
    }

    public void mostraa() {
        System.out.println(marcacoes.toString());
    }

}