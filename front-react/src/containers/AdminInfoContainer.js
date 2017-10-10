import React, {Component} from 'react';

import {AdminInfo, AdminInfoSide} from '../components';


class AdminInfoContainer extends Component{

    constructor(props){

        super(props);
    }

    render(){

        return(
            <div>
                <AdminInfo />
                <AdminInfoSide />
            </div>
        );
    }
}

export default AdminInfoContainer
