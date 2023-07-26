/**
 * A class that shares the same information from clients and transporter
 *
 * @author (your name)
 * @version (a version number or a date)
 */
import java.util.*;
public class Client
{
    private String email;
    private String name;
    private String password;
    private Coordenates address;
    private String birthday;
    
    
    public Client(String email, String name, String password, 
                           String birthday){
                              this.email = email;
                              this.name = name;
                              this.password = password;
                              this.address= address;
                              this.birthday = birthday;
                            }
    public Client(Client c){
        this.email = c.getEmail();
        this.name = c.getName();
        this.password = c. getPassword();
        this.address = c.getAddress();
        this.birthday = c.getBirthday();
    }
    
    public String getEmail(){
        return this.email;
    }
    public void setEmail(String email){
        this.email = email;
    }
    
    public String getName(){
        return this.name;
    }
    public void setName(String name){
        this.name = name;
    }
    
    public String getPassword(){
        return this.password;
    }
    public void setPassword(String password){
        this.password = password;
    }
    
    public Coordenates getAddress(){
        return this.address;
    }
    public void setAddress(){
        this.address = address;
       
    }
    
    public String getBirthday(){
        return this.birthday;
    }
    public void setBirthday(String birthday){
        this.birthday = birthday;
    }
    public Client clone(){
     return new Client(this);
    }   
}
