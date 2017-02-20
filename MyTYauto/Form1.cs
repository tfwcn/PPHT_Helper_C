using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using PPHT_Helper_C;
using System.Threading;

namespace MyTYauto
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private HookProc KeyboardHookProcedure;
        private int hKeyboardHook;
        private Thread t1;
        private bool isStart;
        private MemoryHelper memoryHelper = new MemoryHelper();
        private WindowHelper windowHelper = new WindowHelper();
        private ControlHelper controlHelper = new ControlHelper();
        private ColorHelper colorHelper = new ColorHelper();

        private void Form1_Load(object sender, EventArgs e)
        {
            isStart = true;
            t1 = new Thread(Dosome);
            cbHotKey.DataSource = Enum.GetValues(typeof(Keys));
            HookStart();
        }

        //鼠标Hook结构函数 
        public struct MSG
        {
            public Point p; //坐标
            public IntPtr HWnd;//按键值
            public uint wHitTestCode;
            public int dwExtraInfo;
        }
        //键盘Hook结构函数 
        public struct KeyMSG
        {
            public int vkCode; //按键值
            public int scanCode;
            public int flags;
            public int time;
            public int dwExtraInfo;
        }


        //设置钩子 
        [DllImport("user32.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        private static extern int SetWindowsHookEx(int idHook, HookProc lpfn, int hInstance, int threadId);

        //抽掉钩子 
        [DllImport("user32.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        private static extern bool UnhookWindowsHookEx(int idHook);

        //调用下一个钩子 
        [DllImport("user32.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        private static extern int CallNextHookEx(int idHook, int nCode, IntPtr wParam, IntPtr lParam);

        //委托 
        private delegate int HookProc(int nCode, IntPtr wParam, IntPtr lParam);

        /// <summary>
        /// 安装钩子
        /// </summary>
        public void HookStart()
        {
            if (hKeyboardHook == 0)
            {
                // 创建HookProc实例
                KeyboardHookProcedure = new HookProc(KeyboardHookProc);
                // 设置线程钩子
                hKeyboardHook = SetWindowsHookEx(13, KeyboardHookProcedure, 0, 0);
                // 如果设置钩子失败
                if (hKeyboardHook == 0)
                {
                    HookStop();
                    throw new Exception("SetWindowsHookEx failed.");
                }
            }
        }
        /// <summary>
        /// 卸载钩子
        /// </summary>
        public void HookStop()
        {
            bool retKeyboard = true;
            if (hKeyboardHook != 0)
            {
                retKeyboard = UnhookWindowsHookEx(hKeyboardHook);
                hKeyboardHook = 0;
            }
            if (!(retKeyboard)) throw new Exception("UnhookWindowsHookEx failed.");
        }
        /// <summary>
        /// 信息处理
        /// </summary>
        /// <param name="nCode"></param>
        /// <param name="wParam">按下按键的键值，如果是监听键盘消息的全局钩子，wParam == 0x100键盘按下，wParam == 0x101键盘抬起
        /// <param name="lParam">该值大于零为按下，小于零为抬起</param>
        /// <returns></returns>
        private int KeyboardHookProc(int nCode, IntPtr wParam, IntPtr lParam)
        {
            //监控用户键盘输入
            KeyMSG input = (KeyMSG)Marshal.PtrToStructure(lParam, typeof(KeyMSG));
            if (input.vkCode == (int)cbHotKey.SelectedValue && (int)wParam == 0x100)
            {
                if (t1.ThreadState == ThreadState.Unstarted ||
                    t1.ThreadState == ThreadState.Aborted || 
                    t1.ThreadState == ThreadState.Stopped)
                {
                    t1.Start();
                }
                else
                {
                    t1.Abort();
                    t1 = new Thread(Dosome);
                }
                //return 1;
            }
            // 继续执行下一个钩子程序 
            return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
        }

        private void Dosome()
        {
            string hwnds = memoryHelper.GetHwndsByWindowName("桃园", 1);
            string[] hs = hwnds.Split('|');
            foreach (string val in hs)
            {
                uint hwnd = Convert.ToUInt32(val);
                windowHelper.RestoreWindow(hwnd);
                Thread.Sleep(500);
                windowHelper.SetForegroundWindow(hwnd);
            }
            while (true)
            {
                foreach (string val in hs)
                {
                    uint hwnd = Convert.ToUInt32(val);
                    string csize= windowHelper.GetClientSize(hwnd);
                    int ox, oy;
                    ox = Convert.ToInt32(csize.Split('|')[0]);
                    oy = Convert.ToInt32(csize.Split('|')[1]);
                    if (colorHelper.CheckColorOfPosition(hwnd, 1000, 19,0x84BDD6,10) >0 &&
                        colorHelper.CheckColorOfPosition(hwnd, 922, 276, 0xB5EFFF,10) > 0 &&
                        colorHelper.CheckColorOfPosition(hwnd, 787, 572, 0x6B73F7,10) >0)
                    {
                        windowHelper.SetForegroundWindow(hwnd);
                        Thread.Sleep(100);
                        LMouseDown1(ox + 854, oy + 570);
                        Thread.Sleep(100);
                    }
                }
            }
        }

        private void Move1(int x,int y)
        {
            controlHelper.MouseMove(0, x+1, y+1);
            Thread.Sleep(50);
            controlHelper.MouseMove(0, x, y);
        }

        private void LMouseDown1(int x, int y)
        {
            controlHelper.MouseMove(0, x + 1, y + 1);
            Thread.Sleep(50);
            controlHelper.LMouseClick(0, x, y);
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            HookStop();
            t1.Abort();
        }
    }
}
