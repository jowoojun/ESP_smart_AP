import React, {Component} from 'react';

import {NetworkInfo, NetworkInfoSide} from '../components';
import {getInternetInfo} from '../lib/toServer';

class NetworkInfoContainer extends Component{

    constructor(props){

        super(props);
        this.state = {
            internet_status_code : "",
            my_ip : "",
            default_dns : "",
            sub_dns : "",
            gateway : "",
            DHCP_start_ip : "",
            DHCP_end_ip : "",
            DHCP_MAC_address : ""
        };
    }

    componentDidMount(){
        getInternetInfo()
        .then(response => {
            this.setState(response.data);
        })
        .catch(error => console.log(error));
    }

    render(){

        return(
            <div>
                <NetworkInfo
                    internet_status_code={this.state.internet_status_code}
                    my_ip={this.state.my_ip}
                    default_dns={this.state.default_dns}
                    sub_dns={this.state.sub_dns}
                    gateway={this.state.gateway}
                    DHCP_start_ip={this.state.DHCP_start_ip}
                    DHCP_end_ip={this.state.DHCP_end_ip}
                    DHCP_MAC_address={this.state.DHCP_MAC_address}
                />
                <NetworkInfoSide />
            </div>
        );
    }
}

export default NetworkInfoContainer
