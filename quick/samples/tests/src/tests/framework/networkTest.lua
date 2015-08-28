
local NetworkTestScene = game.createSceneClass("NetworkTestScene")

function NetworkTestScene:ctor()
    self.requestCount = 0

    self:prepare({
        description = "Please check console output"
    })

    local items = {
        "createHTTPRequest",
        "createHTTPRequestBadDomain",
        "send data to server",
        "isLocalWiFiAvailable",
        "isInternetConnectionAvailable",
        "isHostNameReachable",
        "getInternetConnectionStatus",
    }
    self:addChild(game.createMenu(items, handler(self, self.runTest)))
end

function NetworkTestScene:onResponse(event, index, dumpResponse)
    local request = event.request
    printf("REQUEST %d - event.name = %s", index, event.name)
    if event.name == "completed" then
        printf("REQUEST %d - getResponseStatusCode() = %d", index, request:getResponseStatusCode())
        -- printf("REQUEST %d - getResponseHeadersString() =\n%s", index, request:getResponseHeadersString())

        if request:getResponseStatusCode() ~= 200 then
        else
            printf("REQUEST %d - getResponseDataLength() = %d", index, request:getResponseDataLength())
            print("dump:" .. tostring(dumpResponse))
            if dumpResponse then
                printf("REQUEST %d - getResponseString() =\n%s", index, request:getResponseString())
            end
        end
    elseif event.name ~= "progress" then
        -- printf("REQUEST %d - getErrorCode() = %d, getErrorMessage() = %s", index, request:getErrorCode(), request:getErrorMessage())
        print("ErrorCode:" .. tostring(request:getErrorCode()))
        print("ErrowMsg:" .. tostring(request:getErrorMessage()))
    end

    print("----------------------------------------")
end

function NetworkTestScene:createHTTPRequestTest()
    local url = "http://quick-x.com/feed/"
    self.requestCount = self.requestCount + 1
    local index = self.requestCount
    local request = network.createHTTPRequest(function(event)
        if tolua.isnull(self) then
            printf("REQUEST %d COMPLETED, BUT SCENE HAS QUIT", index)
            return
        end
        self:onResponse(event, index)
    end, url, "GET")
    printf("REQUEST START %d", index)
    request:start()
end


function buyItem( itemid )
    价格 ＝ 读表获得(itemId)
    当前金币 ＝ getCurrentGold()
    if 当前金币 >=  价格 then
        return 成功 ， 当前金币 － 价格
    else
        return 失败
    end
end

function  onResponse(event)
    结果 = event:getResponseString()
    结果数组 ＝ 逗号分割（结果）
    if 结果数组［1］ ＝＝ “成功” then
        设置当前的金币（ 结果数组［2］ ）
    else
        显示消息（“金币不足”）
    end
end



function NetworkTestScene:createHTTPRequestBadDomainTest()
    self.requestCount = self.requestCount + 1
    local index = self.requestCount
    local request = network.createHTTPRequest(function(event)
        if tolua.isnull(self) then
            printf("REQUEST %d COMPLETED, BUT SCENE HAS QUIT", index)
            return
        end
        self:onResponse(event, index)
    end, "http://quick-x.com.x.y.z.not/", "GET")
    printf("REQUEST START %d", index)
    request:start()
end



function NetworkTestScene:send_data_to_serverTest()
print("send data to server")
    self.requestCount = self.requestCount + 1
    local index = self.requestCount
    local request = network.createHTTPRequest(function(event)
        if tolua.isnull(self) then
            printf("REQUEST %d COMPLETED, BUT SCENE HAS QUIT", index)
            return
        end
        self:onResponse(event, index, true)

        if event.name == "completed" then
            local cookie = network.parseCookie(event.request:getCookieString())
            dump(cookie, "GET COOKIE FROM SERVER")
        end
    end, "http://quick-x.com/tests/http_request_tests.php", "POST")
    request:addPOSTValue("username", "dualface")
    request:setCookieString(network.makeCookieString({C1 = "V1", C2 = "V2"}))
    printf("REQUEST START %d", index)
    request:start()
end

function NetworkTestScene:isLocalWiFiAvailableTest()
    print("Is local wifi avaibable: ", network.isLocalWiFiAvailable())
end

function NetworkTestScene:isInternetConnectionAvailableTest()
    print("Is internet connection avaibable: ", network.isInternetConnectionAvailable())
end

function NetworkTestScene:isHostNameReachableTest()
    print("Is www.cocos2d-x.org reachable: ", network.isHostNameReachable("www.cocos2d-x.org"))
end

function NetworkTestScene:getInternetConnectionStatusTest()
    local status = {
        [cc.kCCNetworkStatusNotReachable]     = "无法访问互联网",
        [cc.kCCNetworkStatusReachableViaWiFi] = "通过 WIFI",
        [cc.kCCNetworkStatusReachableViaWWAN] = "通过 3G 网络",
    }

    printf("Internet Connection Status: %s", status[network.getInternetConnectionStatus()])
end

return NetworkTestScene
