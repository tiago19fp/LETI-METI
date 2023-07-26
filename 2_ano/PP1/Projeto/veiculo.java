
/**
 * Escreva a descrição da classe veiculo aqui.
 * 
 * @author (seu nome) 
 * @version (número de versão ou data)
 */
public class veiculo
{
  private String marca;
  private String modelo;
  private String tipo;
  private double pHora;
  private double pKm;
  private int autonomia;
  
  public veiculo(){
      this.marca=" ";
      this.modelo=" ";
      this.tipo=" ";
      this.pHora=0;
      this.pKm=0;
      this.autonomia=0;
    }
  public veiculo(String marca,String modelo,String tipo,double pHora,double pKm,int autonomia)
  {
      this.marca=marca;
      this.modelo=modelo;
      this.tipo=tipo;
      this.pHora=pHora;
      this.pKm=pKm;
      this.autonomia=autonomia;
    }
    public veiculo(veiculo v){
    this.marca=v.getMarca();
      this.modelo=v.getModelo();
      this.tipo=v.getTipo();
      this.pHora=v.getPrecoHora();
      this.pKm=v.getPrecoKm();
      this.autonomia=v.getAutonomia();
    }
        public String getMarca(){
        return this.marca=marca;}
        public String getModelo (){
            return this.modelo = modelo;
        }
         public String getTipo (){
            return this.tipo = tipo;
        }
         public double getPrecoHora (){
            return this.pHora = pHora ;
        }
         public double getPrecoKm (){
            return this.pKm = pKm ;
        }
        public int getAutonomia (){
            return this.autonomia = autonomia ;
        }
        public void setMarca(String marca){
        this.marca=marca;
        }
        public void setModelo (String modelo){
            this.modelo = modelo;
        }
         public void setTipo (String tipo){
            this.tipo = tipo;
        }
         public void setPrecoHora (double pHora){
            this.pHora = pHora ;
        }
         public void setPrecoKm (double pKm){
            this.pKm = pKm ;
        }
        public void setAutonomia (int autonomia){
            this.autonomia = autonomia ;
        }
        public veiculo clone(){
        return new veiculo(this);
    }
    public boolean equals(veiculo l)
 {
    if(this == l)
    return true;
    if((l==null) || (this.getClass() != l.getClass() ))
    return false;
    veiculo x=(veiculo) l;
    return (l.getMarca().equals(this.marca) && l.getModelo().equals(this.modelo)
    && l.getTipo().equals(this.tipo) && l.getPrecoHora() == this.pHora && 
    l.getPrecoKm()== this.pKm && l.getAutonomia()== this.autonomia);
}
}



