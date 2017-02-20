using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using PPHT_ApiHook;
using PPHT_Helper_C;
using System.Windows.Forms;

namespace TestApp
{
    class Program
    {
        static void Main(string[] args)
        {
            MemoryHelper memoryHelper = new MemoryHelper();
            string hwnds = memoryHelper.GetHwndsByWindowName("晴空物语", 1);
            string[] hs=hwnds.Split('|');
            uint hwnd = Convert.ToUInt32(hs[0]);
            HookHepler hh = new HookHepler();
            hh.SetHook((int)hwnd);
            hh.RemoveHook();
            //WindowHelper windowHelper = new WindowHelper();
            //windowHelper.MinWindow(hwnd);
            //windowHelper.RestoreWindow(hwnd);
            //windowHelper.SetForegroundWindow(hwnd);
            //ControlHelper controlHelper = new ControlHelper();
            //Thread.Sleep(3000);
            //controlHelper.KeyPress(0, (uint)Keys.P, 1);
            //controlHelper.KeyPress(0, (uint)Keys.P, 1);
            //Thread.Sleep(1000);
            //controlHelper.MouseMove(0, 20-1, 80-1);
            //Thread.Sleep(50);
            //controlHelper.LMouseDown(0, 20, 80);
            //Thread.Sleep(100);
            //controlHelper.LMouseUp(0, 20, 80);
            return;
        }
    }
}
