import org.python.util.PythonInterpreter;
 public class JavaToPythonCall
{
public static void main(String[] args) 
{
PythonInterpreter interpreter = new PythonInterpreter();
try
{

interpreter.execfile("PythonCode.py");
System.out.println("file chali");
}
catch (Exception e) 
{
e.printStackTrace();
}
}
}