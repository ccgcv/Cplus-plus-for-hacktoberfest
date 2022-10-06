class AnyVehicle{
   public:
    void move(){
   System.out.println(“Any vehicle should move!!”);
   }
}
class Bike extends AnyVehicle{
   public:
    void move(){
   System.out.println(“Bike can move too!!”);
   }
}
class Test{
   public static void main(String[] args){
   AnyVehicle vehicle = new Bike();
   // In the above statement, as you can see, the object vehicle is of type AnyVehicle
   // But the output of the below statement will be “Bike can move too!!”, 
   // because the actual implementation of object ‘vehicle’ is decided during runtime vehicle.move();
   vehicle = new AnyVehicle();
   // Now, the output of the below statement will be “Any vehicle should move!!”, 
   vehicle.move();
   }
}