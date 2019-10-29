using System;
using System.Runtime.InteropServices;
using System.Reflection;
using System.IO;
using PInvoke;

namespace DotNet2DEngine
{
    public static class UnmanagedLayer
    {
        #region Static Members
        public static string sUnmanagedDLLPath
        {
            get;
            private set;
        }

        #endregion

        #region Init
        public static void Init()
        {
            // Get the path to the current assembly
            sUnmanagedDLLPath = Assembly.GetExecutingAssembly().CodeBase;
            sUnmanagedDLLPath = new Uri(sUnmanagedDLLPath).LocalPath;
            sUnmanagedDLLPath = Path.GetDirectoryName(sUnmanagedDLLPath);

            // set the path as the first path to search for DLLs when using P/invoke
            Kernel32.SetDllDirectory(sUnmanagedDLLPath);
        }

        #endregion

        #region General Methods

        #region Draw
        [UnmanagedFunctionPointer(CallingConvention.StdCall, CharSet = CharSet.Unicode, SetLastError = true)]
        public delegate void Draw_Delegate();

        [DllImport("2DEngine.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern void Draw_SetCallback(Draw_Delegate callback);
        #endregion

        #region Setup
        [UnmanagedFunctionPointer(CallingConvention.StdCall, CharSet = CharSet.Unicode, SetLastError = true)]
        public delegate void Setup_Delegate();

        [DllImport("2DEngine.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern void Setup_SetCallback(Setup_Delegate callback);
        #endregion

        #region Size
        [DllImport("2DEngine.dll", CallingConvention = CallingConvention.StdCall, SetLastError = true)]
        public static extern bool Size([MarshalAs(UnmanagedType.I4)] int width, [MarshalAs(UnmanagedType.I4)] int height);
        #endregion

        #endregion
    }
}
