import org.python.core.PyObject;
import org.python.util.PythonInterpreter;
 
interface PyFunction
{
public void sumFunction(int a, int b);
}
 
public class JavaToPythonFunction 
{
public static void main(String[] args) {
PythonInterpreter interpreter = new PythonInterpreter();
try 
{
interpreter.exec("from pyMain import sumOfNumbers");
PyObject sumFunction = interpreter.get("sumOfNumbers");
PyFunction function = (PyFunction) sumFunction.__tojava__(PyFunction.class);
function.sumFunction(5, 10);
}
catch (Exception e) 
{
e.printStackTrace();
e.getMessage();
e.toString();
}
}
}