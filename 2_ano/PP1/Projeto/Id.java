/**
 * A class that shares the same information from clients and transporter
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Id
{
    private String email;
    private String name;
    private String password;
    private String address;
    private String birthday;
    
    public Id(String email, String name, String password, 
                          String address, String birthday){
                              this.email = email;
                              this.name = name;
                              this.password = password;
                              this.address = address;
                              this.birthday = birthday;
                            }
    public Id(Id c){
        this.email = c.getEmail();
        this.name = c.getName();
        this.password =c. getPassword();
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
    
    public String getAddress(){
        return this.address;
    }
    public void setAddress(String address){
        this.address = address;
    }
    
    public String getBirthday(){
        return this.birthday;
    }
    public void setBirthday(String birthday){
        this.birthday = birthday;
    }
    public Id clone(){
     return new Id(this);
    }   
}
