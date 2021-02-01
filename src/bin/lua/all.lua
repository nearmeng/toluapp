dofile(path.."compat-5.1.lua")
dofile(path.."compat.lua")
dofile(path.."basic.lua")
dofile(path.."feature.lua")
dofile(path.."verbatim.lua")
dofile(path.."code.lua")
dofile(path.."typedef.lua")
dofile(path.."container.lua")
dofile(path.."package.lua")
dofile(path.."module.lua")
dofile(path.."namespace.lua")
dofile(path.."define.lua")
dofile(path.."enumerate.lua")
dofile(path.."declaration.lua")
dofile(path.."variable.lua")
dofile(path.."array.lua")
dofile(path.."function.lua")
dofile(path.."operator.lua")
dofile(path.."template_class.lua")
dofile(path.."class.lua")
--dofile(path.."clean.lua")
--dofile(path.."custom.lua")
dofile(path.."doit.lua")

local err,msg = xpcall(doit, debug.traceback)
if not err then
--print("**** msg is "..tostring(msg))
 local _,_,label,msg = strfind(msg,"(.-:.-:%s*)(.*)")
 tolua_error(msg,label)
end
