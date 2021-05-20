//  ────────────────────────────────────────────────────────────
//                     ╔╗  ╔╗ ╔══╗      ╔════╗
//                     ║╚╗╔╝║ ╚╣╠╝      ║╔╗╔╗║
//                     ╚╗╚╝╔╝  ║║  ╔══╗ ╚╝║║╚╝
//                      ╚╗╔╝   ║║  ║╔╗║   ║║
//                       ║║   ╔╣╠╗ ║╚╝║   ║║
//                       ╚╝   ╚══╝ ╚══╝   ╚╝
//    ╔╗╔═╗                    ╔╗                     ╔╗
//    ║║║╔╝                   ╔╝╚╗                    ║║
//    ║╚╝╝  ╔══╗ ╔══╗ ╔══╗  ╔╗╚╗╔╝  ╔══╗ ╔╗ ╔╗╔╗ ╔══╗ ║║  ╔══╗
//    ║╔╗║  ║║═╣ ║║═╣ ║╔╗║  ╠╣ ║║   ║ ═╣ ╠╣ ║╚╝║ ║╔╗║ ║║  ║║═╣
//    ║║║╚╗ ║║═╣ ║║═╣ ║╚╝║  ║║ ║╚╗  ╠═ ║ ║║ ║║║║ ║╚╝║ ║╚╗ ║║═╣
//    ╚╝╚═╝ ╚══╝ ╚══╝ ║╔═╝  ╚╝ ╚═╝  ╚══╝ ╚╝ ╚╩╩╝ ║╔═╝ ╚═╝ ╚══╝
//                    ║║                         ║║
//                    ╚╝                         ╚╝
//
//    Lead Maintainer: Roman Kutashenko <kutashenko@gmail.com>
//  ────────────────────────────────────────────────────────────

//-----------------------------------------------------------------------------
function createUser(pc, user, pass) {
    console.log("Create User: ", user)

    let json = {}

    json.command = "script"
    json.script = "create-user.sh"
    json.params = [user, pass]

    pc.invokeCommand(JSON.stringify(json))
}

//-----------------------------------------------------------------------------
function setNetworkParams(pc, interface, isStatic, ip, gateway, dns, mask) {
    console.log("Set network parameters:")
    console.log("    interface: ", interface)

    let json = {}

    json.command = "script"
    json.script = "set-network-params.sh"
    json.params = [interface, isStatic, ip, gateway, dns, mask]

    console.log("    interface : ", interface)
    if (isStatic === "true") {
        console.log("    type      : static")
        console.log("    ip        :", ip)
        console.log("    gateway   :", gateway)
        console.log("    dns       :", dns)
        console.log("    mask      :", mask)
    } else {
        console.log("    type      : dhcp")
    }

    pc.invokeCommand(JSON.stringify(json))
}

//-----------------------------------------------------------------------------
function setupAccessPoint(pc, ssid, mode, password) {
    console.log("Setup access point:")
    console.log("    ssid: ", ssid)
    console.log("    mode: ", mode)

    let json = {}

    json.command = "script"
    json.script = "setup-access-point.sh"
    json.params = [ssid, mode, password]

    pc.invokeCommand(JSON.stringify(json))
}

//-----------------------------------------------------------------------------
function setupVPNRouter(pc, apName, apPass, vpnProvider, user, password) {
    console.log("Setup VPN router:")
    console.log("    AP name : ", apName)
    console.log("    provider: ", vpnProvider)
    console.log("    user    : ", user)

    let json = {}

    json.command = "script"
    json.script = "setup-vpn-router.sh"
    json.params = [apName, apPass, vpnProvider, user, password]

    pc.invokeCommand(JSON.stringify(json))
}

//-----------------------------------------------------------------------------
function enableSSH(pc) {
    console.log("Enable SSH:")

    let json = {}

    json.command = "script"
    json.script = "enable-ssh.sh"
    json.params = []

    pc.invokeCommand(JSON.stringify(json))
}

//-----------------------------------------------------------------------------
function gatewayFromIP(userIP, currentGatewayIP) {
    var ipParts = userIP.split('.')
    if (ipParts.length != 4) {
        return currentGatewayIP
    }
    ipParts[3] = "1"
    return ipParts.join('.')
}

//-----------------------------------------------------------------------------
function enableSSH(pc) {
    console.log("Enable SSH:")

    let json = {}

    json.command = "script"
    json.script = "enable-ssh.sh"
    json.params = []

    pc.invokeCommand(JSON.stringify(json))
}

//-----------------------------------------------------------------------------
function processingText() {
    return ""
}

//-----------------------------------------------------------------------------
function gatewayFromIP(userIP, currentGatewayIP) {
    var ipParts = userIP.split('.')
    if (ipParts.length != 4) {
        return currentGatewayIP
    }
    ipParts[3] = "1"
    return ipParts.join('.')
}

//-----------------------------------------------------------------------------