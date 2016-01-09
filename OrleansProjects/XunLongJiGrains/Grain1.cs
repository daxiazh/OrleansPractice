using System.Threading.Tasks;
using Orleans;
using XunLongJiGrainInterfaces;

namespace XunLongJiGrains
{
    /// <summary>
    /// Grain implementation class Grain1.
    /// </summary>
    public class Grain1 : Grain, IGrain1
    {
        private string _mOldMsg = "Hello World!";

        public Task<string> SayHello(string msg)
        {
            var retmsg = _mOldMsg;
            _mOldMsg = msg;
            return Task.FromResult(retmsg);
        }
    }
}
