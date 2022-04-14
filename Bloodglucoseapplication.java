package org.appinventor;
import com.google.appinventor.components.runtime.HandlesEventDispatching;
import com.google.appinventor.components.runtime.EventDispatcher;
import com.google.appinventor.components.runtime.Form;
import com.google.appinventor.components.runtime.Component;
import com.google.appinventor.components.runtime.TextBox;
import com.google.appinventor.components.runtime.Button;
import com.google.appinventor.components.runtime.Label;
import com.google.appinventor.components.runtime.Image;
import com.google.appinventor.components.runtime.FirebaseDB;
class Screen1 extends Form implements HandlesEventDispatching {
  private TextBox TextBox1;
  private Button Button1;
  private Label Label1;
  private Image Image1;
  private FirebaseDB FirebaseDB1;
  protected void $define() {
    this.AppName("Blood Glucose Monitoring System");
    this.BackgroundImage("back.webp");
    this.Title("Blood Estimation");
    TextBox1 = new TextBox(this);
    TextBox1.Width(LENGTH_FILL_PARENT);
    TextBox1.Hint("Hint for Data");
    Button1 = new Button(this);
    Button1.BackgroundColor(0xFFFFFF00);
    Button1.Width(LENGTH_FILL_PARENT);
    Button1.Text("Receive data");
    Label1 = new Label(this);
    Label1.Text("Due to the estimation above we recommend:");
    Label1.TextColor(0xFFFFFFFF);
    Image1 = new Image(this);
    Image1.Height(-1050);
    Image1.Width(-1075);
    Image1.Picture("reducebloodsugar.jpg");
    FirebaseDB1 = new FirebaseDB(this);
    FirebaseDB1.FirebaseToken(PgzhysdZC33WwHmoodufmTjXeZpT6I1gG4n52bRC);
    FirebaseDB1.FirebaseURL(https://finalproject-d3ec7-default-rtdb.firebaseio.com/);
    FirebaseDB1.ProjectBucket(firebaseconnection);
    EventDispatcher.registerEventForDelegation(this, "ClickEvent", "Click" );
  }
  public boolean dispatchEvent(Component component, String componentName, String eventName, Object[] params){
    if( component.equals(Button1) && eventName.equals("Click") ){
      Button1Click();
      return true;
    }
    return false;
  }
  public void Button1Click(){
    FirebaseDB1.GetValue("", TextBox1.Text());
  }
}