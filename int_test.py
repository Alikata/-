import logging
import os
import subprocess



def system_run_command(command, txt, ignore_stderr = True, additional_env=dict()):
    logging.debug('Run command %s', command)
    cmd_env = os.environ.copy()
    cmd_env.update(additional_env)
    p = subprocess.Popen(command, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                         env=cmd_env,encoding = "utf-8",  text=True)
    output, errors = p.communicate(input = txt )
    if p.returncode or (not ignore_stderr and errors):
        raise IOError("CMD = [{}]\nErrors: {}".format(command, errors if errors else "[]"))
    p.wait()
    result = output
    return result


if __name__ == "__main__":
    result = system_run_command("./wrapper ", txt = "I can't remember why we try\nU 0")
    assert result == "Write your text\nText size 27\nWhich letter in which position you want to change?\nNew text U can't remember why we try\n"
