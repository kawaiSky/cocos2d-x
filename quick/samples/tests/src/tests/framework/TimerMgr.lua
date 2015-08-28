local TimerMgr = class("TimerMgr")
local scheduler = require("framework.scheduler")
local _instance = nil
function TimerMgr:ctor()
	cc(self):addComponent("components.behavior.EventProtocol"):exportMethods()
end


function TimerMgr:start(skillName, time)

    scheduler.scheduleGlobal(function()

    	self:dispatchEvent({
    		name = "skillComplete",
    		skillName = skillName,
    	})
    	
    end, time)
end

function TimerMgr.getInstance()
	if _instance = nil then
		_instance = TimerMgr.new()
	end
	return _instance
end