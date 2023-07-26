import java.util.concurrent.locks.ReentrantLock;

class Bank {

    private static class Account {
        private int balance;

        Account(int balance) {
            this.balance = balance;
        }

        int balance() {
            return balance;
        }

        boolean deposit(int value) {
            balance += value;
            return true;
        }

        boolean withdraw(int value) {
            if (value > balance)
                return false;
            balance -= value;
            return true;
        }
    }

    // Bank slots and vector of accounts
    private int slots;
    private Account[] av;
    ReentrantLock l = new ReentrantLock();

    public Bank(int n) {
        slots = n;
        av = new Account[slots];
        for (int i = 0; i < slots; i++)
            av[i] = new Account(0);
    }

    // Account balance
    public int balance(int id) {
        l.lock();
        try {
            if (id < 0 || id >= slots)
                return 0;
            return av[id].balance();
        } finally {
            l.unlock();
        }
    }

    // Deposit
    boolean deposit(int id, int value) {
        l.lock();
        try {
            if (id < 0 || id >= slots)
                return false;
            return av[id].deposit(value);
        } finally {
            l.unlock();
        }
    }

    // Withdraw; fails if no such account or insufficient balance
    public boolean withdraw(int id, int value) {
        l.lock();
        try {
            if (id < 0 || id >= slots)
                return false;
            return av[id].withdraw(value);
        } finally {
            l.unlock();
        }
    }

    public int totalBalance() {
        int soma = 0;
        l.lock();
        try {
            for (int i = 0; i < slots; i++) {
                soma += balance(i);
            }
        } finally {
            l.unlock();
        }
        return soma;
    }

    public boolean transfer(int from, int to, int value) {
        l.lock();
        try {
            av[from].withdraw(value);
        av[to].deposit(value);
        } finally {
            l.unlock();
        }
        return true;

    }

}