import java.time.LocalDate;
import java.time.LocalDateTime;

public class AEmployee {

    private String name;
    private String id;
    private Integer age;
    private final LocalDate startDate = LocalDate.now();


    public AEmployee( String id,String name, Integer age) {

        this.name = name;
        this.id = id;
        this.age = age;

    }

    public AEmployee( AEmployee employee ){
        this( employee.getId() , employee.getName() , employee.getAge() );
    }

    @Override
    public String toString() {
        return "AEmployee{" +
                "name='" + name + '\'' +
                ", id='" + id + '\'' +
                ", age=" + age +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }
}
