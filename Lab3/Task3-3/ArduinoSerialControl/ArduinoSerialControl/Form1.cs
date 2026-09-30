using System;
using System.IO.Ports;
using System.Windows.Forms;
namespace ArduinoSerialControl
{
    public partial class Form1 : Form
    {
        SerialPort serialPort;
        public Form1()
        {
            InitializeComponent();
            labelStatus.Text = "Arduino 狀態: Button Released!";
            serialPort = new SerialPort("COM7", 9600);
            serialPort.DataReceived += SerialPort_DataReceived;
            serialPort.Open();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            serialPort.Write("1");
        }
        private void button2_Click(object sender, EventArgs e)
        {
            serialPort.Write("0");
        }
        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string message = serialPort.ReadLine();

            Invoke(new Action(() =>
            {
                labelStatus.Text = "Arduino 狀態: " + message;
            }));
        }
    }
}