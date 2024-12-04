#include <iostream>
#include <vector>
#include <string>

class item{
  public:
    virtual std::string GetName() { return ""; };
    virtual float GetPrice () { return 0.0; };
    virtual void GetConfiguration () {};
};

class Processor : public item{
  virtual std::string GetName() { return ""; };
  virtual float GetPrice() { return 0.0; };
  virtual void GetConfiguration() {};
};

class IntelI5 : public Processor{
  virtual std::string GetName() { return "Intel i5"; };
  virtual float GetPrice() { return 3000.0; };
  virtual void GetConfiguration() { std::cout << "1.5Ghz, hasta 2.0Ghz, 2 nucleos, 4 hilos, 8MB cache, 4GB RAM - 8GB RAM" << std::endl; };
};
class IntelI7 : public Processor{
  virtual std::string GetName() { return "Intel i7"; };
  virtual float GetPrice() { return 4700.0; };
  virtual void GetConfiguration() { std::cout << "1.6hz, hasta 1.99hz, 4 nucleos, 8 hilos, 16MB cache, 16GB RAM" << std::endl; };
};
class Drive : public item{
  virtual std::string GetName() { return ""; };
  virtual float GetPrice() { return 0.0; };
  virtual void GetConfiguration() {};
};
class HDD : public Drive{
  virtual std::string GetName() { return "Hard disk drive"; };
  virtual float GetPrice() { return 150.0; };
  virtual void GetConfiguration() { std::cout << "capadidad : 1TB, transferencia de datos 1050 mbits/s" << std::endl; };
};
class SDD : public Drive{
  virtual std::string GetName() { return "Solid state drive"; };
  virtual float GetPrice() { return 270.0; };
  virtual void GetConfiguration() { std::cout << "capacidad : 150GB, transferencia de datos 1800 mbits/s" << std::endl; };
};
class DisplayType : public item{
  virtual std::string GetName() { return ""; };
  virtual float GetPrice() { return 0.0; };
  virtual void GetConfiguration() {};
};
class Normal : public DisplayType{
  virtual std::string GetName() { return "Non-touch screen"; };
  virtual float GetPrice() { return 195.0; };
  virtual void GetConfiguration() { std::cout << "15.6 inch FHD(1920 x 1080), plane, ...etc" << std::endl; };
};
class ExternalDrive : public item{
  virtual std::string GetName() { return ""; };
  virtual float GetPrice() { return 0.0; };
  virtual void GetConfiguration() {};
};
class Monitor : public ExternalDrive{
  virtual std::string GetName() { return ""; };
  virtual float GetPrice() { return 0.0; };
  virtual void GetConfiguration() {};
};
class MonitorLogitech : public Monitor {
  virtual std::string GetName() { return "Monitor Logitech UltraView"; };
  virtual float GetPrice() { return 1500.0; };
  virtual void GetConfiguration() { 
    std::cout << "27 pulgadas, resolución 2560x1440, 144Hz, HDR10, panel IPS" << std::endl; 
  };
};
class MonitorSamsung : public Monitor {
  virtual std::string GetName() { return "Monitor Samsung Odyssey"; };
  virtual float GetPrice() { return 1800.0; };
  virtual void GetConfiguration() { 
    std::cout << "34 pulgadas, resolución 3440x1440, 100Hz, panel curvo VA" << std::endl; 
  };
};
class MonitorDell : public Monitor {
  virtual std::string GetName() { return "Monitor Dell UltraSharp"; };
  virtual float GetPrice() { return 2000.0; };
  virtual void GetConfiguration() { 
    std::cout << "32 pulgadas, resolución 3840x2160, 60Hz, panel IPS, HDR" << std::endl; 
  };
};
class Impresora : public ExternalDrive{
  virtual std::string GetName() { return ""; };
  virtual float GetPrice() { return 0.0; };
  virtual void GetConfiguration() {};
};
class ImpresoraHP : public Impresora {
  virtual std::string GetName() { return "Impresora HP LaserJet Pro"; };
  virtual float GetPrice() { return 1200.0; };
  virtual void GetConfiguration() { 
    std::cout << "Impresora láser, 35 ppm, dúplex automático, conectividad Wi-Fi" << std::endl; 
  };
};
class ImpresoraCanon : public Impresora {
  virtual std::string GetName() { return "Impresora Canon PIXMA G6020"; };
  virtual float GetPrice() { return 1000.0; };
  virtual void GetConfiguration() { 
    std::cout << "Impresora de tinta, impresión a color, conectividad Wi-Fi y USB" << std::endl; 
  };
};
class ImpresoraEpson : public Impresora {
  virtual std::string GetName() { return "Impresora Epson EcoTank L3150"; };
  virtual float GetPrice() { return 950.0; };
  virtual void GetConfiguration() { 
    std::cout << "Impresora de tanque, impresión a color, conectividad Wi-Fi Direct" << std::endl; 
  };
};
class Teclado : public ExternalDrive{
  virtual std::string GetName() { return ""; };
  virtual float GetPrice() { return 0.0; };
  virtual void GetConfiguration() {};
};
class TecladoCorsair : public Teclado {
  virtual std::string GetName() { return "Teclado Mecánico Corsair K95"; };
  virtual float GetPrice() { return 800.0; };
  virtual void GetConfiguration() { 
    std::cout << "Teclado mecánico, switches Cherry MX, retroiluminación RGB, 6 teclas macro" << std::endl; 
  };
};
class TecladoLogitech : public Teclado {
  virtual std::string GetName() { return "Teclado Logitech G Pro"; };
  virtual float GetPrice() { return 700.0; };
  virtual void GetConfiguration() { 
    std::cout << "Teclado mecánico compacto, switches GX Blue, retroiluminación RGB" << std::endl; 
  };
};
class TecladoRazer : public Teclado {
  virtual std::string GetName() { return "Teclado Razer BlackWidow"; };
  virtual float GetPrice() { return 850.0; };
  virtual void GetConfiguration() { 
    std::cout << "Teclado mecánico, switches Razer Green, retroiluminación RGB Chroma" << std::endl; 
  };
};
class laptop{
  public:
    void AddParts(item *item) {
      mLaptopParts.push_back(item);
    }
    float GetCost() {
      float cost = 0.0;
      for(auto item : mLaptopParts) {
        cost += item->GetPrice();
      }
      return cost;
    }
    virtual void GetConfiguration() {
      for(auto i = 0; i < mLaptopParts.size(); i++) {
        std::cout << mLaptopParts[i] -> GetName() << " : ";
        mLaptopParts[i] -> GetConfiguration();
      }
    }
  protected:
    std::vector <item*> mLaptopParts;
};
class laptopBuilder {
  public:
    laptop *opcion1() {
      laptop *lap = new laptop();
      lap -> AddParts(new IntelI5());
      lap -> AddParts(new Normal());
      lap -> AddParts(new HDD());
      return lap;
    }
    laptop *opcion2() {
      laptop *lap = new laptop();
      lap -> AddParts(new IntelI7());
      lap -> AddParts(new Normal());
      lap -> AddParts(new SDD());
      return lap;
    }
};
class computer : public laptop {
  public:
    void set_color(std::string color){ this->color = color;};
    void set_marca(std::string marca){ this->marca = marca;};
    void GetConfiguration() override {laptop::GetConfiguration();std::cout << "El color de su computadora es : " << this->color << "\n La marca de esta computadora es : " << this->marca;};    
  private:
    std::string color;
    std::string marca;
};
class computerBuilder {
public:
    computer* opcion1() {
        computer* comp = new computer();
        comp->AddParts(new IntelI5());
        comp->AddParts(new Normal());
        comp->AddParts(new HDD());
        comp->AddParts(new MonitorLogitech());
        comp->AddParts(new TecladoCorsair());
        comp->AddParts(new ImpresoraEpson());
        comp->set_color("Negro");
        comp->set_marca("Dell");
        return comp;
    }

    computer* opcion2() {
        computer* comp = new computer();
        comp->AddParts(new IntelI7());
        comp->AddParts(new Normal());
        comp->AddParts(new SDD());
        comp->AddParts(new MonitorSamsung());
        comp->AddParts(new TecladoRazer());
        comp->AddParts(new ImpresoraCanon());
        comp->set_color("Plata");
        comp->set_marca("HP");
        return comp;
    }

    computer* opcion3() {
        computer* comp = new computer();
        comp->AddParts(new IntelI5());
        comp->AddParts(new Normal());
        comp->AddParts(new SDD());
        comp->AddParts(new MonitorDell());
        comp->AddParts(new TecladoLogitech());
        comp->AddParts(new ImpresoraHP());
        comp->set_color("Blanco");
        comp->set_marca("Acer");
        return comp;
    }
};
