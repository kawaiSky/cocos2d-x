<?php

define('DS', DIRECTORY_SEPARATOR);
define('BIN_DIR', rtrim(dirname(dirname(__DIR__)), '/\\'));

if (DS == '/')
{
    exec("uname",$ret,$res);
    if ($ret[0] == "Linux") {
        # code...
        define('LUAJIT_BIN','luajit');
        define('LUA_BIN','/usr/local/bin/luac/luac');
    }else{
        define('LUAJIT_BIN', BIN_DIR . '/mac/luajit');
        define('LUA_BIN', BIN_DIR . '/mac/luac');
    }
}
else
{
    define('LUAJIT_BIN', BIN_DIR . '\\win32\\luajit.exe');
    define('LUA_BIN', BIN_DIR . '\\win32\\luac.exe');
}
$isPng = false;
// helper functions

function fetchCommandLineArguments($arg, $options, $minNumArgs = 0)
{
    global $isPng; 
    if (!is_array($arg) || !is_array($options))
    {
        print("ERR: invalid command line arguments");
        return false;
    }
    //var_dump($arg);
    $_ispng = array_search("isPng", $arg);
    var_dump($_ispng);
    if($_ispng){
        $isPng = true;
        array_splice($arg, $_ispng);
    }else{
        $isPng = false;
    }
    //var_dump($arg);
    $config = array();
    $newOptions = array();
    for ($i = 0; $i < count($options); $i++)
    {
        $option = $options[$i];
        $newOptions[$option[0]] = $option;
        $config[$option[1]] = $option[3];
    }
    $options = $newOptions;

    $i = 1;
    while ($i < count($arg))
    {
        $a = $arg[$i];
        if ($a{0} != '-')
        {
            printf("ERR: invalid argument %d: %s", $i, $a);
            return false;
        }

        $a = substr($a, 1);
        if (!isset($options[$a]))
        {
            printf("ERR: invalid argument %d: -%s", $i, $a);
            return false;
        }

        $key = $options[$a][1];
        $num = $options[$a][2];
        $default = $options[$a][3];

        if ($num == 0)
        {
            $config[$key] = true;
        }
        else
        {
            $values = array();
            for ($n = 1; $n <= $num; $n++)
            {
                $values[] = $arg[$i + $n];
            }
            if (count($values) == 1)
            {
                $config[$key] = $values[0];
            }
            else
            {
                $config[$key] = $values;
            }
        }

        $i = $i + $num + 1;
    }

    return $config;
}

function convertConfigValueToString($value)
{
    if (is_null($value))
    {
        return null;
    }
    else if (is_array($value))
    {
        foreach ($value as $k => $v)
        {
            $value[$k] = convertConfigValueToString($v);
        }
    }
    else if (is_string($value))
    {
        return '"' . $value . '"';
    }
    else
    {
        return (string)$value;
    }
}

function dumpConfig($config, $options)
{
    print("config:\n");
    for ($i = 0; $i < count($options); $i++)
    {
        $key = $options[$i][1];
        $value = convertConfigValueToString($config[$key]);
        if ($value != null)
        {
            printf("    %s = %s\n", $key, $value);
        }
    }
    print("\n");
}

function findFiles($dir, array & $files)
{
    global $isPng;

    $dir = rtrim($dir, "/\\") . DS;
    $dh = opendir($dir);
    if ($dh == false) return;

    while (($file = readdir($dh)) !== false)
    {
        if ($file == '.' || $file == '..' || $file == ".DS_Store" ) { continue; }
        //var_dump($file);
        
        //var_dump($fileName);
        
        $path = $dir . $file;
        if (is_dir($path))
        {
            findFiles($path, $files);
        }
        elseif (is_file($path))
        {   
            if ($isPng) {
                $fileName = explode(".",$file);
                if ( $fileName[count($fileName)-1] == "png") {
                    $files[] = $path;
                }
            }else{
                $files[] = $path;
            }
            
            
        }
    }
    closedir($dh);
}

function getScriptFileBytecodes($path, $tmpfile, $usingluajit = 0)
{
    if (!file_exists($path))
    {
        printf("ERR: cannot read Lua source file %s\n", $path);
        return false;
    }

    if (file_exists($tmpfile))
    {
        if (!unlink($tmpfile))
        {
            printf("ERR: cannot remove tmp file %s\n", $tmpfile);
            return false;
        }
    }

    @mkdir(pathinfo($tmpfile, PATHINFO_DIRNAME), 0777, true);

    if ($usingluajit != 0)
    {
        $command = sprintf('%s -b -s "%s" "%s"', LUAJIT_BIN, $path, $tmpfile);
    }
    else
    {
        $command = sprintf('%s -o "%s" "%s"', LUA_BIN, $tmpfile, $path); 
    }
    passthru($command);

    if (!file_exists($tmpfile))
    {
        printf("ERR: cannot compile file %s\n", $path);
        return false;
    }

    return file_get_contents($tmpfile);
}
