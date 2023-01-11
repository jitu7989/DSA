public class AManager extends AEmployee {


    public AManager(String id, String name, Integer age) {
        super(id, name, age);
    }

    public AManager( AEmployee employee ){
        super(employee);
    }

    public AManager copy(){
        return new AManager( this );
    }


}
